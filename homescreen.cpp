#include "homescreen.h"
#include "ui_homescreen.h"
#include<QObject>
#include<QSqlTableModel>
#include"Windows.h"
#include"dbmanager.h"
#include"addpassworddialog.h"

HomeScreen::HomeScreen(QWidget *parent, Windows *windows)
    : QDialog(parent)
    , ui(new Ui::HomeScreen), windows(windows)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

HomeScreen::~HomeScreen()
{
    delete ui;
}

// QByteArray HomeScreen::getDecryptedDatabase()
// {
//     qDebug() << Q_FUNC_INFO;
//     QByteArray decryptedDB = windows->decryptDatabase(windows->databasePath, windows->masterPassword);
//     if (decryptedDB.isEmpty()) {
//         QString text = "error in getDecryptedDatabase()";
//         windows->handleError(text ,1);
//     }
//     return decryptedDB;
// }

void HomeScreen::refreshPage()
{
    qDebug() << Q_FUNC_INFO;
    if (windows->decryptDatabase("database.db", "my_secret_key", DBManager::db)) {
        QSqlTableModel *model = new QSqlTableModel(nullptr, DBManager::db);
        model->setTable("my_table");
        model->select();
    }
}

void HomeScreen::on_addEntryButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    AddPasswordDialog *addEntryDialog = new AddPasswordDialog(this, windows);
    addEntryDialog->setFixedSize(500, 300);
    addEntryDialog->exec();
    refreshPage();
    delete addEntryDialog;
}


void HomeScreen::on_refreshButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << Q_FUNC_INFO;
    modal = new QSqlTableModel;
    modal->setTable("login");
    modal->select();
    ui->tableView->setModel(modal);
}
