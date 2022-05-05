#include "edituser.h"
#include "ui_edituser.h"


EditUser::EditUser(QString username,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUser)

{
    ui->setupUi(this);
    idNum=username.toInt();
    ui->firstNameEmptyLabel->hide();
    ui->lastNameEmptyLabel->hide();
    ui->usernameNotValidLabel->hide();
    data = getUserInformation(username);
    qDebug()<<data;

    //pushing all that info to the various fields
    ui->usernameInput->setText(data[3]);
    ui->firstNameInput->setText(data[0]);
    ui->lastNameInput->setText(data[1]);
    if(data[2] == "admin")
        ui->roleComboBox->setCurrentIndex(2);
    else if(data[2] == "nurse")
        ui->roleComboBox->setCurrentIndex(1);
    else if(data[2] == "doctor")
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
    //need to create db function or mod addUsers to account for changes;
    //first to check if nothing is empty then push forward with the update
    qDebug()<<getPassword(data[0]);
    QString pass = getPassword(data[0]);//used to pass in for the doInputChecks class from base class
    //wanted to use a base class using inheretiance to handle input checks but couldn't figure out how to connect a ui element to execute from the baseclass to calling class
    //but couldn't figure it out and didnt want to waste time to actually figure it out
    //the database class here atleast will use inhereitance now
    bool credsOK = false;
    bool okFirstName = false;
    bool okLastName = false;
    bool okUsername = false;
    QString roleType;

    while(credsOK == false)
    {
        if(ui->firstNameInput->text().isEmpty())
        {
            ui->firstNameEmptyLabel->show();//complain to the user that its empty
            okFirstName=false;
        }
        else
        {
            ui->firstNameEmptyLabel->hide();
            okFirstName=true;
        }

        if(ui->lastNameInput->text().isEmpty())
        {
            ui->lastNameEmptyLabel->show();
            okLastName=false;
        }
        else
        {
            ui->lastNameEmptyLabel->hide();
            okLastName = true;
        }

        if(ui->usernameInput->text().isEmpty())
        {
            ui->usernameNotValidLabel->show();
            okUsername=false;
        }
        else
        {
            ui->usernameNotValidLabel->hide();
            okUsername = true;
        }
        if(ui->roleComboBox->currentIndex()==0)
        {
            roleType = "docto";
        }
        else if(ui->roleComboBox->currentIndex()== 1)
        {
            roleType = "nurse";
        }
        else if(ui->roleComboBox->currentIndex() == 2)
        {
            roleType = "admin";
        }

        if(okFirstName==true&&okLastName==true&&okUsername==true)
        {
            addUser(idNum,ui->usernameInput->text(),ui->firstNameInput->text(),ui->lastNameInput->text(),pass,roleType,2);
            credsOK=true;
        }
        else
            break;
    }



}

void EditUser::cancelButtonPressed()
{
    qDebug()<<"Cancel button was pressed";
}
