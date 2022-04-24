#include "resetpassword.h"
#include "ui_resetpassword.h"
#include "adminwindow.h"

ResetPassword::ResetPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResetPassword)
{
    ui->setupUi(this);
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(okButtonPressed()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancelButtonPressed()));

}

ResetPassword::~ResetPassword()
{
    delete ui;
}

void ResetPassword::okButtonPressed()
{
    if(ui->newPasswordInput->text()==ui->renterPasswordInput->text())
    {
        //pass into db for update

    }
    else
    {
        //complain to the user that the two passwords do not match and go again
        QMessageBox::warning(this,"Warning","These Passwords do not match");
    }
}

void ResetPassword::cancelButtonPressed()
{
    close();
}
