#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, QVector<User> users, QVector<Room> rooms)
    : QMainWindow(parent),
       ui(new Ui::MainWindow), users(users), rooms(rooms)
{
    ui->setupUi(this);

    AccProf = new ProfileAccount(nullptr, &user, rooms, users);
    RegForm = new RegistrationForm();
    connect(ui->exit, &QPushButton::clicked, this, &QApplication::exit);
    connect(AccProf, &ProfileAccount::goToLoginWindow, this, &MainWindow::show);
    connect(ui->reg, &QPushButton::clicked, RegForm, &RegistrationForm::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::CheckEnterData(QLineEdit *log, QLineEdit *pas){
    QString login = log->text();
    QString password = pas ->text();
    qDebug()<<login<<password;
    bool accesser = false;
    QPair<QString, QString> checker;
    for (int i=0;i<users.size(); i++) {
        checker = users[i].getAccount();
        if(checker.first == login && checker.second == password){
            accesser = true;
            user = users[i];
            break;
        }
    }
    return accesser;
}
User MainWindow::getUser(){
    return user;
}
QVector<User> MainWindow::getUsers(){
    return users;
}
QVector<Room> MainWindow::getRooms(){
    return rooms;
}
void MainWindow::on_enter_clicked()
{

    if(CheckEnterData(ui->lineEdit, ui->lineEdit_2)){
        qDebug()<<user.getUserType();
        AccProf->show();
        qDebug()<<"hello";
        AccProf->SetData(&user, user.getCabinet(), users, rooms);
        qDebug()<<"hello";
        AccProf->show();
        this->close();
    }else{
        ui->lineEdit->setText("Invalid login or password");
    }
}

