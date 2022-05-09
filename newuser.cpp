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
        if(ui->firstNameInput->text().isEmpty())//checking if the username has not been filled
        {
            ui->firstNameLabel->setText("First Name (*)");
            ui->firstNameLabel->setStyleSheet("font-weight: bold;color:red;");
            ui->firstNameInput->setPlaceholderText("Cannot be empty");
            okFirstName=false;
        }
        else//if there is something filled preform the neccessary checks
        {
            ui->firstNameLabel->setText("First Name");
            ui->firstNameLabel->setStyleSheet("font-weight: normal;color:black;");
            ui->firstNameInput->setPlaceholderText("");
            okFirstName=true;
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(ui->lastNameInput->text().isEmpty())//check if the last name has been filled or not
        {
            ui->lastNameLabel->setText("First Name (*)");
            ui->lastNameLabel->setStyleSheet("font-weight: bold;color:red;");
            ui->lastNameInput->setPlaceholderText("Cannot be empty");
            okLastName=false;
        }
        else
        {
            ui->lastNameLabel->setText("First Name");
            ui->lastNameLabel->setStyleSheet("font-weight: normal;color:black;");
            ui->lastNameInput->setPlaceholderText("");
            okLastName=true;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(ui->userNameInput->text().isEmpty())//checks if there is a username has been filled
        {
            ui->userNameLabel->setText("Username (*)");
            ui->userNameLabel->setStyleSheet("font-weight:bold;color:red;");
            ui->userNameInput->setPlaceholderText("Username field cannot be empty");
            okUsername = false;
        }
        else
        {
            //username is filled now to check if its avaliable to use
            qDebug()<<"Username field has something in it";
            if(db.userNameAvaliabity(ui->userNameInput->text()))
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
                qDebug()<<"Username is in use";

            }

        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //password badness

        if(ui->passwordInput->text().isEmpty())
        {
            ui->passwordLabel->setText("Password (*)");
            ui->passwordLabel->setStyleSheet("font-weight:bold;color:red");
        }
        else
        {
            qDebug()<<"Password was entered now to check if the reneter password filled";
            if(ui->renterPasswordInput->text().isEmpty())
            {
                ui->reneterPasswordLabel->setText("Renter Password(*)");
                ui->reneterPasswordLabel->setStyleSheet("font-weight:bold;color:red;");
                ui->renterPasswordInput->setPlaceholderText("Renter password");
            }
            else
            {
                if(ui->passwordInput->text()==ui->renterPasswordInput->text())
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
                    okPassword=false;
                }
            }
        }


        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// eveything checks out now to actually add to db ///////////////////////////////////////////////////////////
        if(okFirstName==true&&okLastName==true&&okUsername==true&&okPassword==true)
        {
            credsCheck=true;
            db.addUser(0,ui->userNameInput->text(),ui->firstNameInput->text(),ui->lastNameInput->text(),ui->passwordInput->text(),ui->roleComboBox->currentText(),1);
            //this->close();
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


