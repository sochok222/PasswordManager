#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>
class Windows;

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr, Windows *windows = nullptr);
    ~WelcomeWindow();

private slots:
    void on_openDatabaseButton_clicked();
    void on_createDatabaseButton_clicked();

private:
    Ui::WelcomeWindow *ui;
    Windows *windows;
};

#endif // WELCOMEWINDOW_H
