#include"dbmanager.h"

#include<QString>
#include<QStandardPaths>
#include<QFile>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include <qsqlerror.h>

// QSqlDatabase DBManager::db = QSqlDatabase::addDatabase("QSQLITE");

QSqlDatabase DBManager::db;


// Log for diagnosticks
void DBManager::changeConn(const QString &path)
{
    qDebug() << Q_FUNC_INFO;
    if(db.isOpen())
    {
        db.close();
    }
    db = QSqlDatabase();
    QSqlDatabase::removeDatabase("QSQLITE");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    qDebug() << 2;
    db.setDatabaseName(path);
    qDebug() << 1;
    if(!db.open())
    {
        handleDBError("Can't open database");
    }
}

// Opening default qsqlite connection
void DBManager::openConn()
{
    qDebug() << Q_FUNC_INFO;
}

// Checking if db with users exists
void DBManager::createDatabase(const QString &path, const QString &password)
{
    qDebug() << Q_FUNC_INFO;
    changeConn(path);

    QSqlQuery query(db);

    if (!query.exec("CREATE TABLE IF NOT EXISTS settings ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "password TEXT"
                    ")")) {
        qDebug() << query.lastError();
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS login ("
                    "username TEXT, "
                    "password TEXT"
                    ")")) {
        qDebug() << query.lastError();
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS creditCard ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT, "
                    "password TEXT"
                    ")")) {
        qDebug() << query.lastError();
    }

    uint8_t rowCount=0;
    query.exec("SELECT * FROM settings WHERE id = 1");
    while(query.next())
    {
        rowCount++;
    }
    if(rowCount==0)
    {
        query.prepare("INSERT INTO settings (id, password) VALUES (1, :password)");
        query.bindValue(":password", password);
        QString functionName = Q_FUNC_INFO;

        if(!query.exec())
        {
            db.close();
            handleDBError("Cannot incert row into settings table. " + functionName);
        }
    }
    db.close();
}
