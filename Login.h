#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlError>
#include "newuser.h"
#include "database.h"
#include "adminwindow.h"
#include "doctorview.h"
#include "nurseview.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
private slots:
    void onOK();
    //void createNewUser();
private:
    Ui::Login *ui;
    Database db;
    void openRole(QString);
};
#endif // LOGIN_H
