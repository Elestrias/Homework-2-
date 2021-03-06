#ifndef ACCOUNT_W_H
#define ACCOUNT_W_H

#include <QMainWindow>
#include <dependencies.h>


QT_BEGIN_NAMESPACE
namespace Ui { class ProfileAccount; }
QT_END_NAMESPACE

class ProfileAccount:   public QMainWindow
{
    Q_OBJECT
public:
     ProfileAccount(QWidget *parent = 0);
    ~ProfileAccount();
signals:
    void MainWindow(); // Signal to open Login window
private slots:
    //Slot handler of window changing button
    void logoutButtonPush();
private:
     Ui::ProfileAccount *ui;
};
#endif // ACCOUNT_W_H
