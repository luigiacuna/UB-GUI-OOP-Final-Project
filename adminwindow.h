#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QInputDialog>//unused
#include "database.h"
#include "resetpassword.h"
#include "edituser.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
private slots:
    void about();
    void updateTime();//might need to use in other windows
    void startResetUser();
    void editUser();

    //void on_tableView_activated(const QModelIndex &index);

    void on_usernameView_activated(const QModelIndex &index);

    void on_DeleteUser_clicked();

private:
    Ui::AdminWindow *ui;
    Database db;
    QString val;
};

#endif // ADMINWINDOW_H
