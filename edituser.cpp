#include "edituser.h"
#include "ui_edituser.h"
#include "database.h"

EditUser::EditUser(QString username,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUser)

{
    ui->setupUi(this);
    Database db;
    qDebug()<<db.getUserInformation(username);//checking if all user information is executed
    QStringList data = db.getUserInformation(username);
    //pushing all that info to the various fields
    ui->usernameInput->setText(data[0]);
    ui->firstNameInput->setText(data[1]);
    ui->lastNameInput->setText(data[2]);
    if(data[3] == "admin")
        ui->roleComboBox->setCurrentIndex(2);
    else if(data[3] == "nurse")
        ui->roleComboBox->setCurrentIndex(1);
    else if(data[3] == "docto")
        ui->roleComboBox->setCurrentIndex(0);

    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(okButtonPressed()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancelButtonPressed()));
}

EditUser::~EditUser()
{
    delete ui;
}

void EditUser::okButtonPressed()
{

}

void EditUser::cancelButtonPressed()
{
    qDebug()<<"Cancel button was pressed";
}