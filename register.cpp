#include "register.h"
#include<QDir>
#include<QFile>
#include<QStandardPaths>
#include<QMessageBox>
#include<QLineEdit>
#include "ui_register.h"
#include<QValidator>
#include<QDebug>
#include<QJsonObject>
#include<QSqlError>
#include<QJsonDocument>
#include<QCryptographicHash>
#include <QRegularExpressionValidator>
#include<QCoreApplication>
#include<QVariantList>
#include"dbmanager.h"
#include"windows.h"
QSqlDatabase &db = DBManager::db;

Register::Register(QWidget *parent, Windows *windows)
    : QDialog(parent)
    , ui(new Ui::Register), windows(windows)
{
    ui->setupUi(this);
    ui->passwordLine->setEchoMode(QLineEdit::Password);
}
Register::~Register()
{
    delete ui;
}

// Setting max and minimum lenght of password
void Register::on_passwordLine_textChanged(const QString &text)
{
    qDebug() << Q_FUNC_INFO;
    if (text.length()<=7)
        ui->passwordCheckLine->setText("too short");
    else if (text.length() >= 35)
        ui->passwordCheckLine->setText("too long");
    else
         ui->passwordCheckLine->setText(NULL);
}



// Checks if username and password is good enough
void Register::on_registerButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    QString password = ui->passwordLine->text();
    if((password.length() >= 8 && password.length() <= 35))
    {
        windows->masterPassword = password;
        DBManager::createDatabase(windows->databasePath, windows->masterPassword);
        windows->homePage->refreshPage();
        windows->mw->stackedWidget->setCurrentIndex(3);
    }
    else
    {
        QMessageBox::warning(0, "Error", "Please check your username or password", QMessageBox::Ok, QMessageBox::Ok);
    }
}







void Register::on_backButton_clicked()
{
    windows->mw->stackedWidget->setCurrentIndex(0);
}

