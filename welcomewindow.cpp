#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include<QFileDialog>
#include<QStandardPaths>
#include<QFile>
#include"windows.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, Windows *windows)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow), windows(windows)
{
    ui->setupUi(this);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_createDatabaseButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    QString databasePath = QFileDialog::getSaveFileName(this ,"Create database", QStandardPaths::writableLocation(QStandardPaths::AppDataLocation), "Database file (*.db)");
    qDebug() << "Filename: " << databasePath;
    if(QFile::exists(databasePath))
    {
        qDebug() << "File already exists, deleting...";
        QFile::remove(databasePath);
    }

    windows->databasePath = databasePath;
    windows->mw->stackedWidget->setCurrentIndex(1);
}

void WelcomeWindow::on_openDatabaseButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    QString databasePath = QFileDialog::getSaveFileName(this ,"Open database", QStandardPaths::writableLocation(QStandardPaths::AppDataLocation), "Database file (*.db)");
    qDebug() << "Filename: " << databasePath;


    windows->databasePath = databasePath;
    windows->mw->stackedWidget->setCurrentIndex(2);
}
