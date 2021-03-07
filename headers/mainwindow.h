#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "profileaccount.h"
#include "registartionform.h"
#include "../dependencies.h"
#include "../AccessParametres/User.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr, QVector<User> users= {});
    ~MainWindow();
    bool CheckEnterData(QTextEdit *log, QTextEdit *reg);


private slots:
    void on_enter_clicked();
private:
    Ui::MainWindow *ui;
    ProfileAccount *AccProf;
    RegistrationForm *RegForm;
    QVector<User> users;
    User user;

};

#endif // MAINWINDOW_H
