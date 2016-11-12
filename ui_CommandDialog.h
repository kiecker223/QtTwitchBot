/********************************************************************************
** Form generated from reading UI file 'CommandDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDDIALOG_H
#define UI_COMMANDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CommandDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *DialogOutputNum;
    QTextEdit *responseEdit_1;
    QTextEdit *responseEdit_2;
    QTextEdit *responseEdit_3;
    QTextEdit *responseEdit_4;
    QLabel *label;
    QComboBox *commandSelect;
    QLabel *label_2;
    QPushButton *addDialog;
    QPushButton *deleteButton;
    QPushButton *forceSave;

    void setupUi(QDialog *CommandDialog)
    {
        if (CommandDialog->objectName().isEmpty())
            CommandDialog->setObjectName(QStringLiteral("CommandDialog"));
        CommandDialog->resize(600, 373);
        buttonBox = new QDialogButtonBox(CommandDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(230, 320, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        DialogOutputNum = new QSpinBox(CommandDialog);
        DialogOutputNum->setObjectName(QStringLiteral("DialogOutputNum"));
        DialogOutputNum->setGeometry(QRect(530, 60, 61, 20));
        DialogOutputNum->setFrame(false);
        responseEdit_1 = new QTextEdit(CommandDialog);
        responseEdit_1->setObjectName(QStringLiteral("responseEdit_1"));
        responseEdit_1->setGeometry(QRect(30, 50, 381, 51));
        responseEdit_2 = new QTextEdit(CommandDialog);
        responseEdit_2->setObjectName(QStringLiteral("responseEdit_2"));
        responseEdit_2->setGeometry(QRect(30, 110, 381, 51));
        responseEdit_3 = new QTextEdit(CommandDialog);
        responseEdit_3->setObjectName(QStringLiteral("responseEdit_3"));
        responseEdit_3->setGeometry(QRect(30, 170, 381, 51));
        responseEdit_4 = new QTextEdit(CommandDialog);
        responseEdit_4->setObjectName(QStringLiteral("responseEdit_4"));
        responseEdit_4->setGeometry(QRect(30, 230, 381, 51));
        label = new QLabel(CommandDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 60, 91, 21));
        commandSelect = new QComboBox(CommandDialog);
        commandSelect->setObjectName(QStringLiteral("commandSelect"));
        commandSelect->setGeometry(QRect(30, 10, 381, 22));
        label_2 = new QLabel(CommandDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 10, 131, 16));
        addDialog = new QPushButton(CommandDialog);
        addDialog->setObjectName(QStringLiteral("addDialog"));
        addDialog->setGeometry(QRect(510, 10, 80, 21));
        deleteButton = new QPushButton(CommandDialog);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(450, 100, 141, 21));
        forceSave = new QPushButton(CommandDialog);
        forceSave->setObjectName(QStringLiteral("forceSave"));
        forceSave->setGeometry(QRect(470, 130, 101, 21));

        retranslateUi(CommandDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CommandDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CommandDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CommandDialog);
    } // setupUi

    void retranslateUi(QDialog *CommandDialog)
    {
        CommandDialog->setWindowTitle(QApplication::translate("CommandDialog", "Dialog", 0));
        label->setText(QApplication::translate("CommandDialog", "Response Amount", 0));
        label_2->setText(QApplication::translate("CommandDialog", "Select command", 0));
        addDialog->setText(QApplication::translate("CommandDialog", "ADD DIALOG", 0));
        deleteButton->setText(QApplication::translate("CommandDialog", "Delete Current Command", 0));
        forceSave->setText(QApplication::translate("CommandDialog", "Force Save", 0));
    } // retranslateUi

};

namespace Ui {
    class CommandDialog: public Ui_CommandDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDDIALOG_H
