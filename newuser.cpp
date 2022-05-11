#include "newuser.h"
#include "Login.h"
#include "ui_newuser.h"

NewUser::NewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
    /*ui->firstNameRequired->hide();
    ui->lastNameRequired->hide();
    ui->userNameRequired->hide();
    ui->passwordRequired->hide();
    ui->renterPasswordRequired->hide();*/

    ui->userNameInput->installEventFilter(this);

    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(onOk()));



}

NewUser::~NewUser()
{

    delete ui;
}

void NewUser::onOk()
{
    bool credsCheck = false;

    bool okFirstName=false;
    bool okLastName=false;
    bool okUsername=false;
    bool okPassword=false;


    while(credsCheck==false)//the final ok before executing or preventing addition to the database
    {
        try
        {
            if(ui->firstNameInput->text().isEmpty())//checking if the username has not been filled
            {
                ui->firstNameLabel->setText("First Name (*)");
                ui->firstNameLabel->setStyleSheet("font-weight: bold;color:red;");
                ui->firstNameInput->setPlaceholderText("Cannot be empty");
                okFirstName=false;
                throw 1;
            }
            else//if there is something filled preform the neccessary checks
            {
                ui->firstNameLabel->setText("First Name");
                ui->firstNameLabel->setStyleSheet("font-weight: normal;color:black;");
                ui->firstNameInput->setPlaceholderText("");
                okFirstName=true;
            }
        }
        catch (int x)
        {
            qDebug()<<"ERROR CODE"<<x<<"Empty field First Name";
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        try
        {
            if(ui->lastNameInput->text().isEmpty())//check if the last name has been filled or not
            {
                ui->lastNameLabel->setText("First Name (*)");
                ui->lastNameLabel->setStyleSheet("font-weight: bold;color:red;");
                ui->lastNameInput->setPlaceholderText("Cannot be empty");
                okLastName=false;
                throw 1;
            }
            else
            {
                ui->lastNameLabel->setText("First Name");
                ui->lastNameLabel->setStyleSheet("font-weight: normal;color:black;");
                ui->lastNameInput->setPlaceholderText("");
                okLastName=true;
            }
        }

        catch (int x)
        {
            qDebug()<<"ERROR CODE"<<x<<"Empty field Last Name";
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        try
        {
            if(ui->userNameInput->text().isEmpty())//checks if there is a username has been filled
            {
                ui->userNameLabel->setText("Username (*)");
                ui->userNameLabel->setStyleSheet("font-weight:bold;color:red;");
                ui->userNameInput->setPlaceholderText("Username field cannot be empty");
                okUsername = false;
            }
            else if(userNameAvaliabity(ui->userNameInput->text()))
            {
                ui->userNameLabel->setStyleSheet("font-weight:bold;color:black;");
                ui->userNameInput->setPlaceholderText("");
                okUsername = true;
            }

            else
            {
                ui->userNameLabel->setText("Username (*)");
                ui->userNameLabel->setStyleSheet("font-weight:bold;color-red;");
                ui->userNameInput->setPlaceholderText("This username is already in use");
                okUsername =false;
                throw 2;
            }
        }
        catch (int x)
        {
            qDebug()<<"ERROR CODE"<<x<<"Username is in use";
        }


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        try
        {
            if(ui->passwordInput->text().isEmpty())
            {
                ui->passwordLabel->setText("Password (*)");
                ui->passwordLabel->setStyleSheet("font-weight:bold;color:red");
            }
            else if(ui->renterPasswordInput->text().isEmpty())
            {
                ui->reneterPasswordLabel->setText("Renter Password(*)");
                ui->reneterPasswordLabel->setStyleSheet("font-weight:bold;color:red;");
                ui->renterPasswordInput->setPlaceholderText("Renter password");
            }
            else if(ui->passwordInput->text()==ui->renterPasswordInput->text())
            {
                qDebug()<<"Passwords are a match";
                ui->passwordLabel->setText("Password");
                ui->passwordLabel->setStyleSheet("font-weight:normal;color:black;");
                ui->passwordInput->setPlaceholderText("");
                ui->reneterPasswordLabel->setText("Renter Password");
                ui->reneterPasswordLabel->setStyleSheet("font-weight:normal;color:black;");
                ui->renterPasswordInput->setPlaceholderText("");
                okPassword=true;
            }
            else
            {
                throw 3;
                okPassword=false;
            }
        }
        catch(int x)
        {
            qDebug()<<"ERROR CODE"<<x<<"Password do not match";
        }


        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// eveything checks out now to actually add to db ///////////////////////////////////////////////////////////
        if(okFirstName==true&&okLastName==true&&okUsername==true&&okPassword==true)
        {
            credsCheck=true;
            addUser(0,ui->userNameInput->text(),ui->firstNameInput->text(),ui->lastNameInput->text(),ui->passwordInput->text(),ui->roleComboBox->currentText(),choice);
            this->close();
            //Login log;
            //log.setModal(true);
            //log.exec();
        }
        else
        {
            QMessageBox::warning(this,"Warning","Not finished");
            break;
        }
    }
}


