#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AccProf = new ProfileAccount();
    RegForm = new RegistrationForm();
    connect(ui->exit, &QPushButton::clicked, this, &QApplication::exit);
    connect(AccProf, &ProfileAccount::goToLoginWindow, this, &MainWindow::show);
    connect(ui->reg, &QPushButton::clicked, RegForm, &RegistrationForm::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::CheckEnterData(QTextEdit *log, QTextEdit *pas){
    QString login = log->toPlainText();
    QString password = pas ->toPlainText();
    return false;
}
void MainWindow::on_enter_clicked()
{
    AccProf->show();  // Показываем второе окно
    this->close();    // Закрываем основное окно
}

