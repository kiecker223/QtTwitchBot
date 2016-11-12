/********************************************************************************
** Form generated from reading UI file 'UserData.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDATA_H
#define UI_USERDATA_H

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

class Ui_UserData
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *instructionLabel;

    void setupUi(QDialog *UserData)
    {
        if (UserData->objectName().isEmpty())
            UserData->setObjectName(QStringLiteral("UserData"));
        UserData->resize(327, 294);
        buttonBox = new QDialogButtonBox(UserData);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 240, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(UserData);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 60, 201, 21));
        lineEdit_2 = new QLineEdit(UserData);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 120, 201, 21));
        lineEdit_3 = new QLineEdit(UserData);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 180, 201, 21));
        label = new QLabel(UserData);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 60, 71, 16));
        label_2 = new QLabel(UserData);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 120, 71, 20));
        label_3 = new QLabel(UserData);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 180, 91, 16));
        instructionLabel = new QLabel(UserData);
        instructionLabel->setObjectName(QStringLiteral("instructionLabel"));
        instructionLabel->setGeometry(QRect(20, 20, 291, 16));

        retranslateUi(UserData);
        QObject::connect(buttonBox, SIGNAL(accepted()), UserData, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UserData, SLOT(reject()));

        QMetaObject::connectSlotsByName(UserData);
    } // setupUi

    void retranslateUi(QDialog *UserData)
    {
        UserData->setWindowTitle(QApplication::translate("UserData", "Dialog", 0));
        label->setText(QApplication::translate("UserData", "Bot username", 0));
        label_2->setText(QApplication::translate("UserData", "oauth token", 0));
        label_3->setText(QApplication::translate("UserData", "Your channel name", 0));
        instructionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserData: public Ui_UserData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDATA_H
