#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include "addpassworddialog.h"
#include <QDialog>
#include<QSqlTableModel>

class Windows;
namespace Ui {
class HomeScreen;
}

class HomeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit HomeScreen(QWidget *parent = nullptr, Windows *windows = nullptr);
    ~HomeScreen();

    void createWindow();

    void refreshPage();

    QByteArray getDecryptedDatabase();

private slots:
    void on_addEntryButton_clicked();

    void on_refreshButton_clicked();

private:
    Ui::HomeScreen *ui;
    Windows *windows;
    QSqlTableModel *modal;
    AddPasswordDialog *addEntry;
};

#endif // HOMESCREEN_H
