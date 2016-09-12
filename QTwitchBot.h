#ifndef QTWITCHBOT_H
#define QTWITCHBOT_H

#include <QtNetwork/QTcpSocket>
#include <vector>
#include <QWidget>
#include <QUrl>
#include <QElapsedTimer>
#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QTextBrowser>
#include <QByteArray>
#include <QDesktopServices>
#include <QChar>
#include <QString>
#include <iostream>

using std::vector;

struct UserCommandData
{
    QString  command;
    QString *response;
    int      arraySize;
};

class QTwitchBot : public QTextBrowser
{
    Q_OBJECT
    
public:
    
    QTwitchBot(QWidget *parent = 0);
   ~QTwitchBot();
    
    vector<UserCommandData> commandData;
    
    QByteArray password;
    QByteArray username;
    QByteArray channelName;
    
public slots:
    
    void writeCommandDataToFile();
    void readCommandDataFromFile();
    void onMessageRecieve();
    void connect();
    void disconnect();
    
private:
    
    int           m_messagesSent;
    QElapsedTimer m_timer;
    QTcpSocket   *m_socket;    
    
};

#endif // QTWITCHBOT_H
