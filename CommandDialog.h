#ifndef COMMANDDIALOG_H
#define COMMANDDIALOG_H

#include <QDialog>
#include <QDir>
#include <QLineEdit>
#include <QTextStream>
#include <QSettings>
#include <QFile>
#include <QRect>
#include <QPlainTextEdit>
#include <iostream>

#include "QTwitchBot.h"


namespace Ui 
{
    class CommandDialog;
}

class CommandDialog : public QDialog
{
    Q_OBJECT
    
public:
    
    explicit CommandDialog(QWidget *parent = 0);
    ~CommandDialog();
    
    UserCommandData *dataToSend = new UserCommandData();
    
public slots:
    
    void syncDialogData();    
    void addDialogOption(const QString &value);
    
private slots:
    
    void saveData();
    void on_DialogOutputNum_valueChanged(int arg1);
    void createAddDialogWin();
    
    // Only slots I actually use
    void on_commandSelect_currentIndexChanged(int index);
    void on_deleteButton_released();    
    void on_forceSave_clicked();
    
private:
    
    Ui::CommandDialog *ui;
    
};

#endif // COMMANDDIALOG_H
