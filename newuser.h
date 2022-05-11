#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlDatabase>
#include "database.h"

namespace Ui {
class NewUser;
}

class NewUser : public QDialog, public Database
{
    Q_OBJECT

public:
    explicit NewUser(QWidget *parent = nullptr);
    ~NewUser();
private slots:
    void onOk();
private:
    Ui::NewUser *ui;

};

#endif // NEWUSER_H
