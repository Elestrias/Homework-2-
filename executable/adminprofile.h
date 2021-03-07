#ifndef ADMINPROFILE_H
#define ADMINPROFILE_H

#include <QMainWindow>

namespace Ui {
class AdminProfile;
}

class AdminProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminProfile(QWidget *parent = nullptr);
    ~AdminProfile();

private:
    Ui::AdminProfile *ui;
};

#endif // ADMINPROFILE_H
