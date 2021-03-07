#ifndef PROFILEACCOUNT_H
#define PROFILEACCOUNT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ProfileAccount;
}
QT_END_NAMESPACE

class ProfileAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfileAccount(QWidget *parent = nullptr);
    ~ProfileAccount();

signals:
    void goToLoginWindow();
public slots:
    void on_logout_clicked();
private:
    Ui::ProfileAccount *ui;
};

#endif // PROFILEACCOUNT_H
