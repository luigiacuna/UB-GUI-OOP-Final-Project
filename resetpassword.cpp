#include "resetpassword.h"
#include "ui_resetpassword.h"

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
        db.resetPassword(idNum,ui->newPasswordInput->text());
        QMessageBox::information(this,"Success","Password Reseted!");
        this->close();

    }
    else
    {
        //complain to the user that the two passwords do not match and go again
        QMessageBox::warning(this,"Warning","These Passwords do not match");
    }
}

void ResetPassword::cancelButtonPressed()
{
    AdminWindow admin;
    this->close();
    admin.show();
}
