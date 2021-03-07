#ifndef ADMINPROFILE_H
#define ADMINPROFILE_H

#include <QMainWindow>
#include "profileaccount.h"

namespace Ui {
class AdminProfile;
}

class AdminProfile : public ProfileAccount
{
    Q_OBJECT

public:
    explicit AdminProfile(QWidget *parent = nullptr);
    ~AdminProfile();
private:
    Ui::AdminProfile *ui;
};

#endif // ADMINPROFILE_H
