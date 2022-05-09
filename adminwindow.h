#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QInputDialog>//unused
#include "database.h"
#include "resetpassword.h"
#include "newuser.h"
#include "Login.h"
#include "edituser.h"
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    friend class ResetPassword;
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void about();
    void updateTime();//might need to use in other windows
    void startResetUser();

    //void on_tableView_activated(const QModelIndex &index);

    void on_usernameView_activated(const QModelIndex &index);

    void on_DeleteUser_clicked();

    void on_createUserButton_clicked();

    void on_Logout_clicked();

    void on_editUser_clicked();

private:
    Ui::AdminWindow *ui;
    Database db;
    QString val;
};

#endif // ADMINWINDOW_H
