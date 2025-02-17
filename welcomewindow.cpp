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
    QDir *dir = new QDir;
    dir->mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    delete dir;
    QString databasePath = QFileDialog::getSaveFileName(this ,"Create database", QStandardPaths::writableLocation(QStandardPaths::AppDataLocation), "Database file (*.db)");
    if(QFile::exists(databasePath))
    {
        qDebug() << "File already exists, deleting...";
        QFile::remove(databasePath);
        QFile *file = new QFile(databasePath);
        file->open(QIODevice::ReadWrite);
        file->close();
        delete file;
    }
    qDebug() << "Got database path: " << databasePath;
    windows->databasePath = databasePath;
    qDebug() << "Setting windows database path: " << windows->databasePath;
    windows->mw->stackedWidget->setCurrentIndex(1);
}

void WelcomeWindow::on_openDatabaseButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    QDir *dir = new QDir;
    dir->mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    delete dir;
    QString databasePath = QFileDialog::getSaveFileName(this ,"Open database", QStandardPaths::writableLocation(QStandardPaths::AppDataLocation), "Database file (*.db)");
    qDebug() << "Filename: " << databasePath;
    windows->databasePath = databasePath;
    windows->mw->stackedWidget->setCurrentIndex(2);
}
