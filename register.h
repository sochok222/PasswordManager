#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include<QStandardPaths>

class Windows;

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr, Windows *windows = nullptr);
    ~Register();

private slots:
    void on_registerButton_clicked();
    void on_passwordLine_textChanged(const QString &arg1);
    void on_backButton_clicked();
private:
    Ui::Register *ui;
    Windows *windows;
};


#endif // REGISTER_H
