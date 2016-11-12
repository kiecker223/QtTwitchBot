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
    ui->textBrowser->setPassword(newpassword);
}

void MainWindow::setUsername(const QByteArray &newusername)
{
    ui->textBrowser->setUsername(newusername);
}

void MainWindow::setChannel(const QByteArray &channel)
{
    ui->textBrowser->setChannelName(channel);
}

const QByteArray &MainWindow::Password() const
{
    return ui->textBrowser->password;
}

const QByteArray &MainWindow::UserName() const
{
    return ui->textBrowser->username;
}

const QByteArray &MainWindow::ChannelName() const
{
    return ui->textBrowser->channelName;
}

bool MainWindow::confirmNotDuplicate(const UserCommandData &data)
{
    for (int i = 0; i < ui->textBrowser->commandData.size(); ++i)
    {
        if (ui->textBrowser->commandData[i].command == data.command && 
            ui->textBrowser->commandData[i].responses.size() == data.responses.size())
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
