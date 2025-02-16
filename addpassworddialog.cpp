#include "addpassworddialog.h"
#include "ui_addpassworddialog.h"
#include"Windows.h"
#include<QSqlQuery>
#include<QSqlDatabase>
#include"dbmanager.h"
#include<QDebug>

AddPasswordDialog::AddPasswordDialog(QWidget *parent, Windows *windows)
    : QDialog(parent)
    , ui(new Ui::AddPasswordDialog), windows(windows)
{
    ui->setupUi(this);
}

AddPasswordDialog::~AddPasswordDialog()
{
    delete ui;
}

void AddPasswordDialog::on_saveButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    DBManager::changeConn(windows->databasePath);
    QSqlQuery query(DBManager::db);
    query.prepare("INSERT INTO login (username, password) VALUES (:username, :password)");
    query.bindValue(":username", ui->usernameLine->text());
    query.bindValue(":password", ui->passwordLine->text());
    if(!query.exec())
    {
        QString funcInfo = Q_FUNC_INFO;
        windows->handleError(funcInfo, true);
    }
    emit refreshPageSignal();
    this->destroy();
}

