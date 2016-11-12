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

void QTwitchBot::setPassword(const QByteArray &newPassword)
{
    this->password = newPassword;    
}

void QTwitchBot::setUsername(const QByteArray &newUserName)
{
    this->username = newUserName;
}

void QTwitchBot::setChannelName(const QByteArray &newChannelName)
{
    this->channelName = newChannelName;
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
                if (commandData[i].responses.size() > 1)
                {
                    int t_randNum = qrand() % commandData[i].responses.size();
                    m_socket->write("PRIVMSG #" + channelName.toLower() + " : " + commandData[i].responses[t_randNum].toLatin1() + "\r\n");
                }
                else
                {
                    m_socket->write("PRIVMSG #" + channelName.toLower() + " : " + commandData[i].responses[0].toLatin1() + "\r\n");
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
    
    QTextStream fileTextStream(&t_file);
    
    for (int i = 0; i < commandData.size(); ++i)
    {
        fileTextStream << "|command|: " << commandData[i].command << "`" << endl;
        fileTextStream << "|arraySize|:" << commandData.size() << "`" << endl;
        
        for (int i_ = 0; i_ < commandData[i].responses.size() - 1; ++i_)
        {
            commandData[i].responses[i].remove("\n");
            fileTextStream << "|response" << i_ << "|:" << commandData[i].responses[i_] << "`" << endl;
        }
        fileTextStream << "|endCommand|:" << "`" << endl;
    }
    
    fileTextStream << "|username|:" << username << "`" << endl;
    fileTextStream << "|channelName|:" << channelName << "`" << endl;
    fileTextStream << "|password|:" << password << "`" << endl;
    
    t_file.close();
}

void QTwitchBot::readCommandDataFromFile()
{
    UserCommandData *t_dataToAppend;
    
    QFile t_file("Bot_data.data");
    
    if (t_file.open(QIODevice::ReadOnly | QIODevice::Text) && t_file.exists())
    {
     
        QString fileText = t_file.readAll();
        
        for (int n = 0; n < fileText.size();)
        {        
            int tagEndLoc = fileText.indexOf(":");
            int endLineLoc = fileText.indexOf("`");
            int storedArrSize = 0;
            QString currentTag; 
            
            for (int j = 0; j < tagEndLoc; ++j)
            {
                currentTag += fileText.at(j);
            }
            
            if (currentTag == "|command|")
            {
                QString commandToAppend;
                
                for (int b = tagEndLoc + 1; b < endLineLoc; ++b)
                {
                    commandToAppend.append(fileText.at(b));
                }
                
                commandToAppend.remove(" ");
                
                if (!t_dataToAppend)
                    t_dataToAppend = new UserCommandData;
                t_dataToAppend->command = commandToAppend;                    
            }
            else if (currentTag == "|arraySize|")
            {
                QString tempString;
                
                for (int b = tagEndLoc + 1; b < endLineLoc; ++b)
                {
                    tempString.append(fileText.at(b));
                }
                
                tempString.remove(" ");
                int size = tempString.toInt();
                storedArrSize = size;
            }
            else if (currentTag == "|username|")
            {
                QString tempUsername;
                
                for (int b = tagEndLoc + 1; b < endLineLoc; ++b)
                {
                    tempUsername.append(fileText.at(b));
                }
                
                username = tempUsername.toLatin1();
            }
            else if (currentTag == "|channelName|")
            {
                QString tempChannelName;
                
                for (int b = tagEndLoc + 1; b < endLineLoc; ++b)
                {
                    tempChannelName.append(fileText.at(b));
                }
                
                channelName = tempChannelName.toLatin1();
            }
            else if (currentTag == "|password|")
            {
                QString tempPassword;
                
                for (int b = tagEndLoc + 1; b < endLineLoc; ++b)
                {
                    tempPassword.append(fileText.at(b));
                }
                
                password = tempPassword.toLatin1();
            }
            else if (currentTag.contains("|response"))
            {
                int currentResponse;
                
                QString tempStr = currentTag;
                tempStr.remove(0, 9);
                tempStr.remove(1, 2);
                
                currentResponse = tempStr.toInt();
                
                QString response;
                
                for (int i = tagEndLoc + 1; i < endLineLoc; ++i)
                {
                    response.append(fileText.at(i));
                }
                
                t_dataToAppend->responses.push_back(response);
                
                // Trigger an assertion if we have more responses than
                // we stored, not likely to be triggered
                Q_ASSERT(!(currentResponse > storedArrSize));
            }
            else if (currentTag == "|endCommand|")
            {
                commandData.push_back(*t_dataToAppend);
                delete t_dataToAppend;
            }
            fileText.remove(0, fileText.indexOf("\n") + 1);
        }
        t_file.close();
    }
    else
    {
        this->append("No file was found, don't "
                     "worry this might be your first time using it");
    }        
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
    
    m_socket->waitForConnected();
    
    if (m_socket->isValid())
    {
        this->append("Connection established");
    }
    
    this->append("Starting upload");
    
    m_socket->write("PASS oauth:" + password.toLower() + "\r\n");
    m_socket->write("NICK " + username.toLower() + "\r\n");
    m_socket->write("USER " + username.toLower() + " " + username.toLower() + " " + username.toLower() + " : " + username.toLower() + " \r\n");
    m_socket->write("JOIN #" + channelName.toLower() + "\r\n");
    
    
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
