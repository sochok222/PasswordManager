/********************************************************************************
** Form generated from reading UI file 'addpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPASSWORDDIALOG_H
#define UI_ADDPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddPasswordDialog
{
public:
    QLineEdit *passwordLine;
    QLineEdit *usernameLine;
    QLabel *label;
    QLabel *label_2;
    QPushButton *saveButton;

    void setupUi(QDialog *AddPasswordDialog)
    {
        if (AddPasswordDialog->objectName().isEmpty())
            AddPasswordDialog->setObjectName("AddPasswordDialog");
        AddPasswordDialog->resize(457, 303);
        passwordLine = new QLineEdit(AddPasswordDialog);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setGeometry(QRect(130, 100, 231, 24));
        usernameLine = new QLineEdit(AddPasswordDialog);
        usernameLine->setObjectName("usernameLine");
        usernameLine->setGeometry(QRect(130, 60, 231, 24));
        label = new QLabel(AddPasswordDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 71, 16));
        label_2 = new QLabel(AddPasswordDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 100, 71, 16));
        saveButton = new QPushButton(AddPasswordDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(180, 170, 80, 24));

        retranslateUi(AddPasswordDialog);

        QMetaObject::connectSlotsByName(AddPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPasswordDialog)
    {
        AddPasswordDialog->setWindowTitle(QCoreApplication::translate("AddPasswordDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddPasswordDialog", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("AddPasswordDialog", "Password: ", nullptr));
        saveButton->setText(QCoreApplication::translate("AddPasswordDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPasswordDialog: public Ui_AddPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPASSWORDDIALOG_H
