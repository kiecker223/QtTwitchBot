#ifndef TWITCHBOTDIALOG_H
#define TWITCHBOTDIALOG_H

#include <QDialog>
#include <QString>
#include <QSignalMapper>
#include <QByteArray>
#include <QVector>

namespace Ui 
{
    class TwitchBotDialog;
}

class TwitchBotDialog : public QDialog
{
    Q_OBJECT
    
public:
    
    explicit TwitchBotDialog(QWidget *parent = 0);
    ~TwitchBotDialog();
    
public slots:
    
    void sendCommand();
    
private:
    
    QString m_command;
    QSignalMapper *m_signalMapper = new QSignalMapper;
    
    Ui::TwitchBotDialog *ui;
};

#endif // TWITCHBOTDIALOG_H
