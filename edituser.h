#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>
#include "database.h"

namespace Ui {
class EditUser ;
}

class EditUser : public QDialog, public Database
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
    QStringList data;
    int idNum;
};

#endif // EDITUSER_H
