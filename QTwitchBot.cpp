#include "QTwitchBot.h"

#include <QtGlobal>
#include <string>


QTwitchBot::QTwitchBot(QWidget *parent) : QTextBrowser(parent)
{    
    m_pSocket = new QTcpSocket(this);
    
    QObject::connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(onMessageRecieve()));
    
    this->append("Socket bound");
    
    readCommandDataFromFile();
}

QTwitchBot::~QTwitchBot()
{
    writeCommandDataToFile();
    
    delete m_pSocket;
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
    QString data = m_pSocket->readLine();
    
    if (m_timer.elapsed() >= 30000)
    {
        m_messagesSent = 0;
        m_timer.restart();
        m_timer.start();
        
        this->append("Restarting timer");
    }
    
    // If its a message
    // TODO: Make cleaner!
    if (data.contains("PRIVMSG #"))
    {
        data.remove("PRIVMSG #");
        
        int indexOfUsernameEnd = data.indexOf("!");
        
        QString t_messagerUsername = "";
        
        for (int i = 1; i < indexOfUsernameEnd; ++i)
        {
            t_messagerUsername += data.at(i);
        }
        
        data.remove(t_messagerUsername);
        data.remove(QString(":!@.tmi.twitch.tv"));
        data.remove(QString(channelName));
        
        for (int i = 0; i < t_messagerUsername.length(); ++i)
        {
            data.insert(i, t_messagerUsername.at(i).toLatin1());
        }
        
        this->append(data);
        
        // message should look something like : twitchUser: Message
        // Now to check for commands
        for (int i = 0; i < commandData.size(); ++i)
        {
            if (data.contains(commandData[i].command) && m_messagesSent < 100)
            {
                m_messagesSent++;
                std::string t_temp = std::to_string(m_messagesSent);
                
                this->append(t_temp.c_str());
                if (commandData[i].responses.size() > 1)
                {
                    int randNum = qrand() % commandData[i].responses.size();
                    m_pSocket->write("PRIVMSG #" + channelName.toLower() + " : " + commandData[i].responses[randNum].toLatin1() + "\r\n");
                }
                else
                {
                    m_pSocket->write("PRIVMSG #" + channelName.toLower() + " : " + commandData[i].responses[0].toLatin1() + "\r\n");
                }
            }
        }
    }    
    // Ping request?
    if (data.contains(QString("PING :tmi.twitch.tv")))
    {
        m_pSocket->write("PONG :tmi.twitch.tv \r\n");
    }
    
    if (m_pSocket->canReadLine())
    {
        onMessageRecieve();
    }
}

void QTwitchBot::writeCommandDataToFile()
{
    QFile file("Bot_data.data");
    
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        this->append("Well it appears that we couldn't create the neccessary file for this app");
        return;
    }
    
    QTextStream fileTextStream(&file);
    
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
    
    file.close();
}

void QTwitchBot::readCommandDataFromFile()
{
    UserCommandData *dataToAppend;
    
    QFile file("Bot_data.data");
    
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) && file.exists())
    {
     
        QString fileText = file.readAll();
        
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
                
                if (!dataToAppend)
                    dataToAppend = new UserCommandData;
                dataToAppend->command = commandToAppend;                    
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
                
                dataToAppend->responses.push_back(response);
                
                // Trigger an assertion if we have more responses than
                // we stored, not likely to be triggered
                Q_ASSERT(!(currentResponse > storedArrSize));
            }
            else if (currentTag == "|endCommand|")
            {
                commandData.push_back(*dataToAppend);
                delete dataToAppend;
            }
            fileText.remove(0, fileText.indexOf("\n") + 1);
        }
        file.close();
    }
    else
    {
        this->append("No file was found, don't "
                     "worry this might be your first time using it");
    }        
}

void QTwitchBot::connect()
{
    QString serverName = "irc.chat.twitch.tv";
    
    if (m_pSocket->state() == QTcpSocket::ConnectedState 
      || m_pSocket->state() == QTcpSocket::ConnectingState)
    {
        this->append("we are already connected");
        return;
    }
    
    m_pSocket->connectToHost(serverName, 6667);
    
    this->append("Connection Started... \n");
    
    m_pSocket->waitForConnected();
    
    if (m_pSocket->isValid())
    {
        this->append("Connection established");
    }
    
    this->append("Starting upload");
    
    m_pSocket->write("PASS oauth:" + password.toLower() + "\r\n");
    m_pSocket->write("NICK " + username.toLower() + "\r\n");
    m_pSocket->write("USER " + username.toLower() + " " + username.toLower() + " " + username.toLower() + " : " + username.toLower() + " \r\n");
    m_pSocket->write("JOIN #" + channelName.toLower() + "\r\n");
    
    m_timer.start();
}

void QTwitchBot::disconnect()
{
    // Very last step
    m_pSocket->write("PRIVMSG #" + channelName.toLower() + " : Well everyone, see you another time (^ U ^)/ \r\n");
    m_pSocket->flush();
    m_pSocket->disconnectFromHost();
    
    this->append("Disconnected");
}
