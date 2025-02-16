#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QStandardPaths>
#include<QDir>
#include<QMessageBox>
#include<QVBoxLayout>
#include<QPushButton>
#include<QUiLoader>
#include<QStackedWidget>
#include"register.h"
#include<QtExceptionHandling>
#include"windows.h"


// ↓↓↓This is list of windows that MainWindow costructor loads to stackedWidget↓↓↓
// stackedWidget index:
// 0 - welcomewindow.ui
// 1 - register.ui
// 2 - login.ui

// MainWindow constructor, this constructor also creates Windows class instance of Windows class that have pointers to all windows
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << Q_FUNC_INFO;
    ui->setupUi(this);

    // adding QStackedWidget in Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(stackedWidget);

    // setting Layout for central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    Windows *windows = new Windows(this);
    stackedWidget->addWidget(windows->welcomePage);
    stackedWidget->addWidget(windows->registerPage);
    stackedWidget->addWidget(windows->loginPage);
    stackedWidget->addWidget(windows->homePage);

    stackedWidget->setCurrentIndex(0);
}
MainWindow::~MainWindow()
{
    delete ui;
}





// Translator of this program
// void MainWindow::on_comboBox_currentIndexChanged(int index)
// {
//     qDebug() << "MainWindow::on_comboBox_currentIndexChanged() ← Function to change language in program, named so bad";
//     try{
//         bool set;
//         if (index == 1)
//         {
//             set = qtLanguageTranslator.load("language_ua");
//             qApp->installTranslator(&qtLanguageTranslator);
//         }
//         else if (index == 0)
//         {
//             set = qtLanguageTranslator.load("language_en");
//             qApp->installTranslator(&qtLanguageTranslator);






