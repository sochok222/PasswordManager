/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QLabel *label_2;
    QPushButton *createDatabaseButton;
    QPushButton *openDatabaseButton;

    void setupUi(QDialog *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName("WelcomeWindow");
        WelcomeWindow->resize(535, 394);
        label_2 = new QLabel(WelcomeWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 20, 171, 16));
        createDatabaseButton = new QPushButton(WelcomeWindow);
        createDatabaseButton->setObjectName("createDatabaseButton");
        createDatabaseButton->setGeometry(QRect(130, 200, 91, 24));
        openDatabaseButton = new QPushButton(WelcomeWindow);
        openDatabaseButton->setObjectName("openDatabaseButton");
        openDatabaseButton->setGeometry(QRect(300, 200, 91, 24));

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QDialog *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QCoreApplication::translate("WelcomeWindow", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("WelcomeWindow", "welcome to password manager", nullptr));
        createDatabaseButton->setText(QCoreApplication::translate("WelcomeWindow", "Create database", nullptr));
        openDatabaseButton->setText(QCoreApplication::translate("WelcomeWindow", "Open database", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
