#include "adminprofile.h"
#include "ui_adminprofile.h"

AdminProfile::AdminProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminProfile)
{
    ui->setupUi(this);
}

AdminProfile::~AdminProfile()
{
    delete ui;
}
