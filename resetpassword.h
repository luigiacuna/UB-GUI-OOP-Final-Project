#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>

namespace Ui {
class ResetPassword;
}

class ResetPassword : public QDialog
{
    Q_OBJECT

public:
    explicit ResetPassword(QWidget *parent = nullptr);
    ~ResetPassword();
private slots:
    void okButtonPressed();
    void cancelButtonPressed();

private:
    Ui::ResetPassword *ui;
};

#endif // RESETPASSWORD_H
