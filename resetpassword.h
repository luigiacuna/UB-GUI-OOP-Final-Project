#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>
#include "database.h"

namespace Ui {
class ResetPassword;
}

class ResetPassword : public QDialog, public Database
{
    Q_OBJECT

public:
    explicit ResetPassword(QString id,QWidget *parent = nullptr);
    ~ResetPassword();
private slots:
    void okButtonPressed();
    void cancelButtonPressed();

private:
    Ui::ResetPassword *ui;
    QString idNum;
};

#endif // RESETPASSWORD_H
