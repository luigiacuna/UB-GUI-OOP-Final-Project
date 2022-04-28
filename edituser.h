#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>

namespace Ui {
class EditUser;
}

class EditUser : public QDialog
{
    Q_OBJECT

public:
    explicit EditUser(QString username,QWidget *parent = nullptr);
    ~EditUser();
private slots:
    void okButtonPressed();
    void cancelButtonPressed();

private:
    Ui::EditUser *ui;
};

#endif // EDITUSER_H
