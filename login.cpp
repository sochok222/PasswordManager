#include "login.h"
#include "ui_login.h"
#include<QRegularExpression>
#include<QMessageBox>
#include"windows.h"


Login::Login(QWidget *parent, Windows *windows)
    : QDialog(parent)
    , ui(new Ui::Login), windows(windows)
{
    ui->setupUi(this);
    ui->passwordLine->setEchoMode(QLineEdit::Password);
    // connect(ui->usernameLine, SIGNAL(textChanged(const QString &)), this, SLOT(on_usernameLine_textChanged(const QString &)));
}

Login::~Login()
{
    delete ui;
}

// Password line check
void Login::on_loginButton_clicked()
{
    qDebug() << Q_FUNC_INFO;
    QString password = ui->passwordLine->text();
    if((password.length() >= 8 && password.length() <= 35))
    {
        qDebug() << "Some login proccess...";

    }
    else
    {
        QMessageBox::warning(0, "Error", "Please check your password", QMessageBox::Ok, QMessageBox::Ok);
    }
}

// filtering text in username line
// void Login::on_usernameLine_textChanged(const QString &text)
// {
//     if (text.length()<=4)
//         ui->usernameCheckLine->setText("too short");
//     else if (text.length() >= 20)
//         ui->usernameCheckLine->setText("too long");
//     else
//         ui->usernameCheckLine->setText(NULL);
//     // deleting spaces and special symbols
//     QString filteredText = text;
//     filteredText.remove(QRegularExpression("[\\s\\t\\n]"));
//     filteredText.remove(QRegularExpression("[^a-zA-Z0-9\\-_]"));
//     // text refresh
//     ui->usernameLine->setText(filteredText);
//     // set cursor at the end of line
//     ui->usernameLine->setCursorPosition(filteredText.length());
// }

// setting max and minimum lenght of password
void Login::on_passwordLine_textChanged(const QString &text)
{
    if (text.length()<=7)
        ui->passwordCheckLine->setText("too short");
    else if (text.length() >= 35)
        ui->passwordCheckLine->setText("too long");
    else
        ui->passwordCheckLine->setText(NULL);
}

void Login::on_returnButton_clicked()
{
    windows->mw->stackedWidget->setCurrentIndex(0);
}

