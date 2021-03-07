#include "../headers/registartionform.h"
#include "ui_registartionform.h"

RegistrationForm::RegistrationForm(QWidget *parent, QVector<User> * users) :
    QDialog(parent), pntr(users),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);

}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}
