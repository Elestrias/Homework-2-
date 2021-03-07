#ifndef PROFILEACCOUNT_H
#define PROFILEACCOUNT_H

#include <QMainWindow>
#include"AccessParametres/User.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class ProfileAccount;
}
QT_END_NAMESPACE

class ProfileAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfileAccount(QWidget *parent = nullptr, User *user=nullptr, QVector<Room> rooms = {}, QVector<User> users = {});
    ~ProfileAccount();
    void SetData(User *user, QString personalCabinet="No Cabinet", QVector<User>users={}, QVector<Room> rooms={});

signals:
    void goToLoginWindow();
public slots:
    void on_logout_clicked();
    void on_getAccess_clicked();
    void on_apllyChanges_clicked();
    void on_ApplyOpen_clicked();
private:
    QVector<Room> rooms;
    QVector <User> people;
    User *user;
    Ui::ProfileAccount *ui;
};

#endif // PROFILEACCOUNT_H
