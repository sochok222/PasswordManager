/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *loginButton;
    QLineEdit *passwordLine;
    QLabel *passwordLabel;
    QLabel *usernameCheckLine;
    QLabel *passwordCheckLine;
    QLabel *greetingLabel;
    QPushButton *backButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(550, 328);
        Login->setWindowOpacity(1.000000000000000);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(120, 200, 75, 24));
        loginButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        passwordLine = new QLineEdit(Login);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setGeometry(QRect(170, 120, 191, 21));
        passwordLabel = new QLabel(Login);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(90, 120, 61, 20));
        usernameCheckLine = new QLabel(Login);
        usernameCheckLine->setObjectName("usernameCheckLine");
        usernameCheckLine->setGeometry(QRect(390, 60, 49, 16));
        passwordCheckLine = new QLabel(Login);
        passwordCheckLine->setObjectName("passwordCheckLine");
        passwordCheckLine->setGeometry(QRect(390, 110, 49, 16));
        greetingLabel = new QLabel(Login);
        greetingLabel->setObjectName("greetingLabel");
        greetingLabel->setGeometry(QRect(90, 70, 181, 16));
        backButton = new QPushButton(Login);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(20, 10, 80, 24));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "LogIn", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Login", "password:", nullptr));
        usernameCheckLine->setText(QString());
        passwordCheckLine->setText(QString());
        greetingLabel->setText(QString());
        backButton->setText(QCoreApplication::translate("Login", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
