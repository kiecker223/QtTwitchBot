#include "TwitchBotDialog.h"
#include "ui_TwitchBotDialog.h"
#include "CommandDialog.h"
#include <iostream>

#define PARENT ((CommandDialog *)parentWidget())

TwitchBotDialog::TwitchBotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwitchBotDialog)
{
    ui->setupUi(this);
    
    connect(this, SIGNAL(accepted()), this, SLOT(sendCommand()));
}

TwitchBotDialog::~TwitchBotDialog()
{
    delete ui;
}

void TwitchBotDialog::sendCommand()
{
    PARENT->addDialogOption(ui->lineEdit->text());
    PARENT->dataToSend->command = ui->lineEdit->text();
}
