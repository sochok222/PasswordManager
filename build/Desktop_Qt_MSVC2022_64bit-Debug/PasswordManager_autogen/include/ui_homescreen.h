/********************************************************************************
** Form generated from reading UI file 'homescreen.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMESCREEN_H
#define UI_HOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_HomeScreen
{
public:
    QLabel *label;
    QTableView *tableView;
    QPushButton *addEntryButton;
    QPushButton *refreshButton;

    void setupUi(QDialog *HomeScreen)
    {
        if (HomeScreen->objectName().isEmpty())
            HomeScreen->setObjectName("HomeScreen");
        HomeScreen->resize(474, 355);
        label = new QLabel(HomeScreen);
        label->setObjectName("label");
        label->setGeometry(QRect(198, 20, 121, 20));
        tableView = new QTableView(HomeScreen);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(120, 60, 256, 192));
        addEntryButton = new QPushButton(HomeScreen);
        addEntryButton->setObjectName("addEntryButton");
        addEntryButton->setGeometry(QRect(200, 280, 80, 24));
        refreshButton = new QPushButton(HomeScreen);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(340, 280, 80, 24));

        retranslateUi(HomeScreen);

        QMetaObject::connectSlotsByName(HomeScreen);
    } // setupUi

    void retranslateUi(QDialog *HomeScreen)
    {
        HomeScreen->setWindowTitle(QCoreApplication::translate("HomeScreen", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("HomeScreen", "homescreen page", nullptr));
        addEntryButton->setText(QCoreApplication::translate("HomeScreen", "Add entry", nullptr));
        refreshButton->setText(QCoreApplication::translate("HomeScreen", "refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeScreen: public Ui_HomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREEN_H
