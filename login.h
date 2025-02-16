#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"mainwindow.h"

class Windows;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr, Windows *windows = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void on_passwordLine_textChanged(const QString &text);
    void on_returnButton_clicked();

public:
    Ui::Login *ui;
    MainWindow *mw;
    Windows *windows;
};

#endif // LOGIN_H
