#ifndef REGISTARTIONFORM_H
#define REGISTARTIONFORM_H

#include <QDialog>
#include "AccessParametres/User.h"

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = nullptr, QVector<User> *users=nullptr);
    ~RegistrationForm();
private:
    QString name;
    QString surname;
    AccessType accessType;
    QVector<User> * pntr;
    Ui::RegistrationForm *ui;
};

#endif // REGISTARTIONFORM_H
