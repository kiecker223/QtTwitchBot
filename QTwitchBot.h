#ifndef QTWITCHBOT_H
#define QTWITCHBOT_H

#include <QtNetwork/QTcpSocket>
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
#include <QtGui/qmatrix4x4.h>

using std::vector;

struct UserCommandData
{
    QString          command;
    QVector<QString> responses;
};

class QTwitchBot : public QTextBrowser
{
    Q_OBJECT
    
    QMatrix4x4 mat3;
    
public:
    
    QTwitchBot(QWidget *parent = 0);
   ~QTwitchBot();
    
    vector<UserCommandData> commandData;
    
    QByteArray password;
    QByteArray username;
    QByteArray channelName;
    
public slots:
    
    void setPassword(const QByteArray &newPassword);
    void setUsername(const QByteArray &newUserName);
    void setChannelName(const QByteArray &newChannelName);
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
