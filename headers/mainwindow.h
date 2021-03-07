#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "profileaccount.h"
#include "registartionform.h"
#include "../dependencies.h"
#include "../AccessParametres/User.h"
#include "../AccessParametres/Room.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr, QVector<User> users= {}, QVector<Room> rooms = {});
    ~MainWindow();
    bool CheckEnterData(QLineEdit *log, QLineEdit *reg);
    User getUser();
    QVector<User> getUsers();
    QVector<Room> getRooms();
    void ChangeUser(User user);
    int index_of_cur_user;


private slots:
    void on_enter_clicked();
private:
    Ui::MainWindow *ui;
    ProfileAccount *AccProf;
    RegistrationForm *RegForm;
    QVector<User> users;
    QVector<Room> rooms;
    User user;
};

#endif // MAINWINDOW_H
