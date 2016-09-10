#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSettings>
#include <QMainWindow>

#include "CommandDialog.h"
#include "QTwitchBot.h"

using std::vector;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    vector<UserCommandData> *getQTwitchBotData();
    
    void setPassword(const QByteArray &newpassword);
    void setUsername(const QByteArray &username);
    void setChannel(const QByteArray &channel);
    
    bool confirmNotDuplicate(const UserCommandData &data);
    
public slots:
    
    void addDialogOption(const UserCommandData &commandData);
    
private slots:
    
    void on_textBrowser_destroyed();
    void createCommandDialog();
    void openUserInfo();
    
private:
    
    QSettings m_settings;
    Ui::MainWindow *ui;
    
};

#endif // MAINWINDOW_H
