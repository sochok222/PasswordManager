#ifndef DBMANAGER_H
#define DBMANAGER_H

#include<QString>
#include<QMessageBox>
#include<QStandardPaths>
#include<QFile>
#include<QtSql/QSqlDatabase>
#include<QCoreApplication>
#include<QFile>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<QMessageBox>


class DBManager
{
private:
    static void handleDBError(const QString &errorMessage)
    {
        qDebug() << Q_FUNC_INFO;
        QMessageBox msg;
        msg.setText("Error message: " + errorMessage);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        exit(EXIT_FAILURE);
    }
public:
    static QSqlDatabase db;
    static void changeConn(const QString &path);
    static void openConn();
    static void createDatabase(const QString &path, const QString &password);
};

#endif // DBMANAGER_H
