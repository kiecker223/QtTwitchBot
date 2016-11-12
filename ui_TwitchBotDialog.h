/********************************************************************************
** Form generated from reading UI file 'TwitchBotDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWITCHBOTDIALOG_H
#define UI_TWITCHBOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_TwitchBotDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *TwitchBotDialog)
    {
        if (TwitchBotDialog->objectName().isEmpty())
            TwitchBotDialog->setObjectName(QStringLiteral("TwitchBotDialog"));
        TwitchBotDialog->resize(240, 167);
        buttonBox = new QDialogButtonBox(TwitchBotDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 120, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(TwitchBotDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 221, 21));
        label = new QLabel(TwitchBotDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 16));

        retranslateUi(TwitchBotDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TwitchBotDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TwitchBotDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TwitchBotDialog);
    } // setupUi

    void retranslateUi(QDialog *TwitchBotDialog)
    {
        TwitchBotDialog->setWindowTitle(QApplication::translate("TwitchBotDialog", "Dialog", 0));
        label->setText(QApplication::translate("TwitchBotDialog", "Command", 0));
    } // retranslateUi

};

namespace Ui {
    class TwitchBotDialog: public Ui_TwitchBotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWITCHBOTDIALOG_H
