#include "account_w.h"
#include "ui_account_w.h"
#include "dependencies.h"

ProfileAccount::ProfileAccount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProfileAccount)
{
    ui->setupUi(this);
}

ProfileAccount::~ProfileAccount()
{
    delete ui;
}

void ProfileAccount::logoutButtonPush()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
