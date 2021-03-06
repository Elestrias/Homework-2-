#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "profileaccount.h"
#include "registartionform.h"
#include "dependencies.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool CheckEnterData(QTextEdit *log, QTextEdit *reg);

private slots:
    void on_enter_clicked();
private:
    Ui::MainWindow *ui;
    ProfileAccount *AccProf;
    RegistrationForm *RegForm;
};

#endif // MAINWINDOW_H
