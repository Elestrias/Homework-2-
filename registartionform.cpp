#include "registartionform.h"
#include "ui_registartionform.h"

RegistrationForm::RegistrationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);
}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}
