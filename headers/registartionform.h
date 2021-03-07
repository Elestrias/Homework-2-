#ifndef REGISTARTIONFORM_H
#define REGISTARTIONFORM_H

#include <QDialog>

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm();
private:
    Ui::RegistrationForm *ui;
};

#endif // REGISTARTIONFORM_H
