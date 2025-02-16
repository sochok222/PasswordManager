#include"mainwindow.h"
#include<QTranslator>
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QApplication>
#include<QDir>
#include<QStandardPaths>

int main(int argc, char *argv[])
{
    qDebug() << Q_FUNC_INFO;
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();
    return a.exec();
}
