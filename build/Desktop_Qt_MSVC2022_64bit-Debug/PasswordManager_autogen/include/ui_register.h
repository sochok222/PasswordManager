/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *registerButton;
    QLabel *label_4;
    QLineEdit *passwordLine;
    QLabel *passwordCheckLine;
    QLabel *checkInput;
    QPushButton *backButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(448, 332);
        registerButton = new QPushButton(Register);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(160, 220, 131, 41));
        label_4 = new QLabel(Register);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 110, 61, 16));
        passwordLine = new QLineEdit(Register);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setGeometry(QRect(120, 110, 231, 22));
        passwordCheckLine = new QLabel(Register);
        passwordCheckLine->setObjectName("passwordCheckLine");
        passwordCheckLine->setGeometry(QRect(360, 110, 91, 16));
        passwordCheckLine->setAlignment(Qt::AlignmentFlag::AlignCenter);
        checkInput = new QLabel(Register);
        checkInput->setObjectName("checkInput");
        checkInput->setGeometry(QRect(170, 140, 121, 20));
        backButton = new QPushButton(Register);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 10, 80, 21));
        QFont font;
        font.setPointSize(10);
        backButton->setFont(font);
        backButton->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        registerButton->setText(QCoreApplication::translate("Register", "Create database", nullptr));
        label_4->setText(QCoreApplication::translate("Register", "Password:", nullptr));
        passwordCheckLine->setText(QString());
        checkInput->setText(QString());
        backButton->setText(QCoreApplication::translate("Register", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
