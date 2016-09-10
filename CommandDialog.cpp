#include "CommandDialog.h"
#include "ui_CommandDialog.h"
#include "MainWindow.h"
#include "TwitchBotDialog.h"
#include <QDebug>

#define COMMAND_LIST ((MainWindow *)parentWidget())->getQTwitchBotData()
#define PARENT       ((MainWindow *)parentWidget())


CommandDialog::CommandDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommandDialog)
{
    ui->setupUi(this); 
    
    ui->responseEdit_1->hide();
    ui->responseEdit_2->hide();
    ui->responseEdit_3->hide();
    ui->responseEdit_4->hide();
    
    ui->DialogOutputNum->setMaximum(4);
    ui->DialogOutputNum->setMinimum(1);
    
    for (int i = 0; i < COMMAND_LIST->size(); ++i)
    {
        ui->commandSelect->addItem(COMMAND_LIST->at(i).command);
    }
    
    connect(ui->addDialog, SIGNAL(clicked(bool)), this, SLOT(createAddDialogWin()));
}

CommandDialog::~CommandDialog()
{
    this->clearFocus();
    
    // Save on exit
    saveData();
    
    // Cleanup
    if (dataToSend != nullptr)
    {
        delete dataToSend;
    }
    
    delete ui;
}

// For now only support 4 random resposes associated with 1 command
// And now I collapse it and never look at it again because that was lazy programming :P
void CommandDialog::on_DialogOutputNum_valueChanged(int arg1)
{
    if (arg1 >= 1)
    {
        ui->responseEdit_1->show();
    }
    if (arg1 >= 2)
    {
        ui->responseEdit_2->show();
    }
    if (arg1 >= 3)
    {
        ui->responseEdit_3->show();
    }
    if (arg1 >= 4)
    {
        ui->responseEdit_4->show();
    }
    if (arg1 < 4)
    {
        ui->responseEdit_4->hide();
    }
    if (arg1 < 3)
    {
        ui->responseEdit_3->hide();
    }
    if (arg1 < 2)
    {
        ui->responseEdit_2->hide();
    }
    if (arg1 < 1)
    {
        ui->responseEdit_1->hide();
    }
}

void CommandDialog::syncDialogData()
{
    if (COMMAND_LIST->at(ui->commandSelect->currentIndex()).arraySize >= 1)
        ui->responseEdit_1->setText(COMMAND_LIST->at(ui->commandSelect->currentIndex()).response[0]);
    
    if (COMMAND_LIST->at(ui->commandSelect->currentIndex()).arraySize >= 2)
        ui->responseEdit_2->setText(COMMAND_LIST->at(ui->commandSelect->currentIndex()).response[1]);
    
    if (COMMAND_LIST->at(ui->commandSelect->currentIndex()).arraySize >= 3)
        ui->responseEdit_3->setText(COMMAND_LIST->at(ui->commandSelect->currentIndex()).response[2]);
    
    if (COMMAND_LIST->at(ui->commandSelect->currentIndex()).arraySize >= 4)
        ui->responseEdit_4->setText(COMMAND_LIST->at(ui->commandSelect->currentIndex()).response[3]);
    
    dataToSend->command = ui->commandSelect->currentText();
    ui->DialogOutputNum->setValue(COMMAND_LIST->at(ui->commandSelect->currentIndex()).arraySize);
}

void CommandDialog::saveData()
{
    int i = ui->commandSelect->currentIndex();
    dataToSend->arraySize = ui->DialogOutputNum->value();
    dataToSend->response = new QString[dataToSend->arraySize];
    
    // Existing commands
    if (i < COMMAND_LIST->size())
    {
        if (COMMAND_LIST->at(i).command == ui->commandSelect->currentText())
        {
            if (COMMAND_LIST->at(i).arraySize >= 1 && ui->responseEdit_1->toPlainText().size() >= 1)
                COMMAND_LIST->at(i).response[0].append(ui->responseEdit_1->toPlainText());
            
            if (COMMAND_LIST->at(i).arraySize >= 2 && ui->responseEdit_2->toPlainText().size() >= 1)
                COMMAND_LIST->at(i).response[1].append(ui->responseEdit_2->toPlainText());
            
            if (COMMAND_LIST->at(i).arraySize >= 3 && ui->responseEdit_3->toPlainText().size() >= 1)
                COMMAND_LIST->at(i).response[2].append(ui->responseEdit_3->toPlainText());
            
            if (COMMAND_LIST->at(i).arraySize == 4 && ui->responseEdit_4->toPlainText().size() >= 1)
                COMMAND_LIST->at(i).response[3].append(ui->responseEdit_4->toPlainText());
        }
    }
    // New command
    else
    {
        if (dataToSend->arraySize >= 1 && ui->responseEdit_1->toPlainText().size() >= 1)
            dataToSend->response[0] = ui->responseEdit_1->toPlainText();
        
        if (dataToSend->arraySize >= 2 && ui->responseEdit_2->toPlainText().size() >= 1)
            dataToSend->response[1] = ui->responseEdit_2->toPlainText();
        
        if (dataToSend->arraySize >= 3 && ui->responseEdit_3->toPlainText().size() >= 1)
            dataToSend->response[2] = ui->responseEdit_3->toPlainText();
        
        if (dataToSend->arraySize >= 4 && ui->responseEdit_4->toPlainText().size() >= 1)
            dataToSend->response[3] = ui->responseEdit_4->toPlainText();
    }
    
    for (int i = 0; i < dataToSend->arraySize; ++i)
    {
        qDebug() << dataToSend->response[i];
    }
    
    // If it isn't a duplicate append it
    if (PARENT->confirmNotDuplicate(*dataToSend))
    {
        COMMAND_LIST->push_back(*dataToSend);
    }
    
    delete dataToSend;
    dataToSend = new UserCommandData();
}

void CommandDialog::addDialogOption(const QString &value)
{
    ui->commandSelect->addItem(value);
}

void CommandDialog::createAddDialogWin()
{
    TwitchBotDialog *b = new TwitchBotDialog(this);
    b->show();
    b->exec();
    
    delete b;
}

void CommandDialog::on_commandSelect_currentIndexChanged(int index)
{
    // If we selected a new command
    if (index + 1 > COMMAND_LIST->size())
    {
        // no data to sync
        ui->responseEdit_1->clear();
        ui->responseEdit_2->clear();
        ui->responseEdit_3->clear();
        ui->responseEdit_4->clear();
        
        saveData();
    }
    // If we selected an existing command
    else
    {
        syncDialogData();
    }
}

void CommandDialog::on_deleteButton_released()
{
    COMMAND_LIST->erase(COMMAND_LIST->begin() + ui->commandSelect->currentIndex());
}


