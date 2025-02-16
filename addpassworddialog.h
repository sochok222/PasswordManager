#ifndef ADDPASSWORDDIALOG_H
#define ADDPASSWORDDIALOG_H

#include <QDialog>

class Windows;
namespace Ui {
class AddPasswordDialog;
}

class AddPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPasswordDialog(QWidget *parent = nullptr, Windows *windows = nullptr);
    ~AddPasswordDialog();

private slots:
    void on_saveButton_clicked();

signals:
    void refreshPageSignal();

private:
    Ui::AddPasswordDialog *ui;
    Windows *windows;
};

#endif // ADDPASSWORDDIALOG_H
