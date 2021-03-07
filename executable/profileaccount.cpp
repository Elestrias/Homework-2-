#include "../headers/profileaccount.h"
#include "ui_profileaccount.h"
#include "../dependencies.h"
#include "../headers/mainwindow.h"

ProfileAccount::ProfileAccount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProfileAccount)
{
    ui->setupUi(this);
    connect(ui->exit, &QPushButton::clicked, this, &QApplication::exit);
     }

ProfileAccount::~ProfileAccount()
{
    delete ui;
}

void ProfileAccount::on_logout_clicked(){
    this->close();
    emit goToLoginWindow();
}
