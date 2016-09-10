#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "UserData.h"

#include <QThread>
#include <QtGlobal>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Connect button pushed ?
    connect(ui->connectButton, SIGNAL(clicked(bool)), ui->textBrowser, SLOT(connect()));
    
    // Quit button pushed ?
    connect(ui->quitButton, SIGNAL(clicked(bool)), ui->textBrowser, SLOT(disconnect()));

    // Add some dialog ?
    connect(ui->editDialog, SIGNAL(clicked(bool)), this, SLOT(createCommandDialog()));
    
    // test
    connect(ui->loginButton, SIGNAL(clicked(bool)), this, SLOT(openUserInfo()));
    
    if (!m_settings.contains("channel") && !m_settings.contains("username") && !m_settings.contains("password"))
    {
        ui->textBrowser->append("You haven't set up your information yet");
        ui->textBrowser->append("Press \"login\" to set up your information");
    }
    else
    {
        if (m_settings.contains("channel"))
        {
            ui->textBrowser->channelName = m_settings.property("channel").toByteArray();
        }
        if (m_settings.contains("username"))
        {
            ui->textBrowser->username = m_settings.property("username").toByteArray();
        }
        if (m_settings.contains("password"))
        {
            ui->textBrowser->password = m_settings.property("password").toByteArray();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<UserCommandData> *MainWindow::getQTwitchBotData()
{
    return &ui->textBrowser->commandData;
}

void MainWindow::setPassword(const QByteArray &newpassword)
{
    ui->textBrowser->password = newpassword;
    
    m_settings.setValue("password", newpassword);
}

void MainWindow::setUsername(const QByteArray &newusername)
{
    ui->textBrowser->username = newusername;
    
    m_settings.setValue("username", newusername);
}

void MainWindow::setChannel(const QByteArray &channel)
{
    ui->textBrowser->channelName = channel;
    
    m_settings.setValue("channel", channel);
}

bool MainWindow::confirmNotDuplicate(const UserCommandData &data)
{
    for (int i = 0; i < ui->textBrowser->commandData.size(); ++i)
    {
        if (ui->textBrowser->commandData[i].command == data.command && 
            ui->textBrowser->commandData[i].arraySize == data.arraySize)
        {
            return false;
        }
    }
    
    return true;
}

void MainWindow::addDialogOption(const UserCommandData &command)
{
    ui->textBrowser->commandData.push_back(command);
}

void MainWindow::openUserInfo()
{
    UserData *t_userTab = new UserData(this);
    t_userTab->show();
    t_userTab->exec();
    
    delete t_userTab;
}

void MainWindow::createCommandDialog()
{
    CommandDialog *t_commandDialog = new CommandDialog(this);
    t_commandDialog->show();
    t_commandDialog->exec();
    
    delete t_commandDialog;
}

void MainWindow::on_textBrowser_destroyed() { }
