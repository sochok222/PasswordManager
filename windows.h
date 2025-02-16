#ifndef WINDOWS_H
#define WINDOWS_H
#include"mainwindow.h"
#include"homescreen.h"
#include"register.h"
#include"welcomewindow.h"
#include<QString>
#include<QObject>
#include<QMessageBox>
#include"login.h"


class Windows
{
public:
    explicit Windows(MainWindow *mw = nullptr);
    MainWindow *mw;
    Windows *windows = this;
    WelcomeWindow *welcomePage = new WelcomeWindow(mw, this);
    Register *registerPage = new Register(mw, this);
    Login *loginPage = new Login(mw, this);
    HomeScreen *homePage = new HomeScreen(mw, this);
    QString databasePath;
    QString masterPassword;
    QString iv = "I will create realization for this later";
    void handleError(const QString &text, bool closeProgram)
    {
        QMessageBox msg;
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText(text);
        msg.exec();
        if(closeProgram)
            exit(EXIT_FAILURE);
    }
    ~Windows(){
        delete this;
    }
    QByteArray encryptDatabase(const QString &filePath, const QByteArray &data, const QString &key);
    bool createEncryptedDatabase(const QString &dbPath, const QString &key);
    bool decryptDatabase(const QString &filePath, const QString &key, QSqlDatabase &db);
};

#endif // WINDOWS_H
