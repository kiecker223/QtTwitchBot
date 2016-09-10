#include "QTwitchBot.h"

#include <QtGlobal>
#include <string>


QTwitchBot::QTwitchBot(QWidget *parent) : QTextBrowser(parent)
{
    m_socket = new QTcpSocket(this);
    
    QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(onMessageRecieve()));
    
    this->append("Socket bound");
    
    readCommandDataFromFile();
}

QTwitchBot::~QTwitchBot()
{
    writeCommandDataToFile();
    
    delete m_socket;
}

void QTwitchBot::onMessageRecieve()
{
    QString t_data = m_socket->readLine();
    
    if (m_timer.elapsed() >= 30000)
    {
        m_messagesSent = 0;
        m_timer.restart();
        m_timer.start();
        
        this->append("Restarting timer");
    }
    
    // If its a message
    // TODO: Make cleaner!
    if (t_data.contains("PRIVMSG #"))
    {
        t_data.remove("PRIVMSG #");
        
        int t_indexOfUsernameEnd = t_data.indexOf("!");
        
        QString t_messagerUsername = "";
        
        for (int i = 1; i < t_indexOfUsernameEnd; ++i)
        {
            t_messagerUsername += t_data.at(i);
        }
        
        t_data.remove(t_messagerUsername);
        t_data.remove(QString(":!@.tmi.twitch.tv"));
        t_data.remove(QString(channelName));
        
        for (int i = 0; i < t_messagerUsername.length(); ++i)
        {
            t_data.insert(i, t_messagerUsername.at(i).toLatin1());
        }
        
        this->append(t_data);
        
        // message should look something like : twitchUser: Message
        // Now to check for commands
        for (int i = 0; i < commandData.size(); ++i)
        {
            if (t_data.contains(commandData[i].command) && m_messagesSent < 100)
            {
                m_messagesSent++;
                std::string t_temp = std::to_string(m_messagesSent);
                
                this->append(t_temp.c_str());
                if (commandData[i].arraySize > 1)
                {
                    int t_randNum = qrand() % commandData[i].arraySize;
                    m_socket->write("PRIVMSG #" + channelName.toLower() + " : " + commandData[i].response[t_randNum].toLatin1() + "\r\n");
                }
                else
                {
                    m_socket->write("PRIVMSG #" + channelName.toLower() + " : " + commandData[i].response[0].toLatin1() + "\r\n");
                }
            }
        }
    }    
    // Ping request?
    if (t_data.contains(QString("PING :tmi.twitch.tv")))
    {
        m_socket->write("PONG :tmi.twitch.tv \r\n");
    }
    
    if (m_socket->canReadLine())
    {
        onMessageRecieve();
    }
}

void QTwitchBot::writeCommandDataToFile()
{
    QFile t_file("Bot_data.data");
    
    if (!t_file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        this->append("Well it appears that we couldn't create the neccessary file for this app");
        return;
    }
    
    QTextStream t_dataToWrite(&t_file);
    
    for (int i = 0; i < commandData.size(); ++i)
    {
        t_dataToWrite << "|command|: " << commandData[i].command << endl;
        t_dataToWrite << "|arraySize|: " << commandData[i].arraySize << endl;
        
        int t_arrSize = commandData[i].arraySize;
        
        if (t_arrSize == 1)
        {
            t_dataToWrite << "|response0|:" << commandData[i].response[0] << endl;
        }
        else
        {
            for (int i_ = 0; i_ < t_arrSize - 1; ++i_)
            {
                t_dataToWrite << "|response" << i_ << "|:" << commandData[i].response[i_] << endl;
            }
        }
    }
    
    t_file.close();
}

void QTwitchBot::readCommandDataFromFile()
{
    UserCommandData *t_dataToAppend;
    
    QFile t_file("Bot_data.data");
    
    if (t_file.open(QIODevice::ReadOnly | QIODevice::Text) && t_file.exists())
    {
        QString t_data = t_file.readAll();
        for (int b = 0; b < t_data.length();)
        {
            if (t_data[b] == QChar('|'))
            {
                int t_tagEndLoc = t_data.indexOf(":");
                QString t_tag;
                
                for (int i = b; i < t_tagEndLoc; ++i)
                {
                    t_tag += t_data.at(i);
                }
                
                if (t_tag == "|command|")
                {
                    int t_endLineLoc = t_data.indexOf("\n");
                    QString t_commandToAppend;
                    
                    for (int i = t_tagEndLoc + 1; i < t_endLineLoc; ++i)
                    {
                        t_commandToAppend += t_data.at(i);
                    }
                    
                    t_commandToAppend.remove(" ");                    
                    t_dataToAppend = new UserCommandData();
                    t_dataToAppend->command = t_commandToAppend;
                    t_data.remove(0, t_endLineLoc + 1);
                }
                else if (t_tag == "|arraySize|")
                {
                    int t_endLineLoc = t_data.indexOf("\n");
                    QString t_arrayNumToAppend;
                    
                    for (int i = t_tagEndLoc + 1; i < t_endLineLoc; ++i)
                    {
                        t_arrayNumToAppend += t_data.at(i);
                    }
                    
                    t_dataToAppend->arraySize = t_arrayNumToAppend.toInt();
                    t_dataToAppend->response = new QString[t_dataToAppend->arraySize];
                    t_data.remove(0, t_endLineLoc + 1);
                }
                for (int a = 0; a < 4; ++a)
                {
                    QString t_tagToCompare = "|response";
                    t_tagToCompare += std::to_string(a).c_str();
                    t_tagToCompare += "|";
                    if (t_tag == t_tagToCompare)
                    {
                        int t_endLineLoc = t_data.indexOf("\n");
                        QString t_responseToAppend;
                        
                        for (int i = t_tagEndLoc + 1; i < t_endLineLoc; ++i)
                        {
                            t_responseToAppend += t_data.at(i);
                        }
                        t_dataToAppend->response[a] = (t_responseToAppend);
                        if (t_dataToAppend->arraySize == 1)
                        {
                            commandData.push_back(*t_dataToAppend);
                            delete t_dataToAppend;
                        }
                        t_data.remove(0, t_endLineLoc + 1);
                        break;
                    }
                }
            }
            else
            {
                ++b;
            }
        }
    }
    
    t_file.close();
}

void QTwitchBot::connect()
{
    QString t_serverName = "irc.chat.twitch.tv";
    
    if (m_socket->state() == QTcpSocket::ConnectedState 
      || m_socket->state() == QTcpSocket::ConnectingState)
    {
        this->append("we are already connected");
        return;
    }
    
    m_socket->connectToHost(t_serverName, 6667);
    
    this->append("Connection Started... \n");
    
    if (m_socket->waitForConnected())
    {
        if (m_socket->isValid())
        {
            this->append("Connection established");
        }
        
        this->append("Starting upload");
        
        m_socket->write("PASS oauth:" + password.toLower() + "\r\n");
        m_socket->write("NICK " + username.toLower() + "\r\n");
        m_socket->write("USER " + username.toLower() + " " + username.toLower() + " " + username.toLower() + " : " + username.toLower() + " \r\n");
        m_socket->write("JOIN #" + channelName.toLower() + "\r\n");
    }
    
    m_timer.start();
}

void QTwitchBot::disconnect()
{
    // Very last step
    m_socket->write("PRIVMSG #" + channelName.toLower() + " : Well everyone, see you another time (^ U ^)/ \r\n");
    m_socket->flush();
    m_socket->disconnectFromHost();
    
    this->append("Disconnected");
}
