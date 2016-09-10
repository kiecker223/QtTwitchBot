#include "UserData.h"
#include "ui_UserData.h"
#include "MainWindow.h"

#define PARENT ((MainWindow *)parentWidget())

UserData::UserData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserData)
{
    ui->setupUi(this);
    
    ui->instructionLabel->setText("instructions for how to use this <a href=\"https://www.github.com\"> here </a>");
    ui->instructionLabel->setTextFormat(Qt::RichText);
    ui->instructionLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->instructionLabel->setOpenExternalLinks(true);
}

UserData::~UserData()
{
    delete ui;
}

void UserData::on_buttonBox_accepted()
{
    this->clearFocus();
    
    PARENT->setUsername(ui->lineEdit->text().toLatin1());
    PARENT->setPassword(ui->lineEdit_2->text().toLatin1());
    PARENT->setChannel(ui->lineEdit_3->text().toLatin1());
}
