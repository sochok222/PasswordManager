#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTranslator>
#include<QStackedWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStackedWidget *stackedWidget = new QStackedWidget(this);
    QStackedWidget *getStackedWidget()
    {
        return stackedWidget;
    }

private slots:
    // void on_comboBox_currentIndexChanged(int index);

public:
    Ui::MainWindow *ui;
    QTranslator qtLanguageTranslator;
};
#endif // MAINWINDOW_H
