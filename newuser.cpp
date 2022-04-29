#include "newuser.h"
#include "Login.h"
#include "ui_newuser.h"

NewUser::NewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
    ui->firstNameRequired->hide();
    ui->lastNameRequired->hide();
    ui->userNameRequired->hide();
    ui->passwordRequired->hide();
    ui->renterPasswordRequired->hide();

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
           ui->firstNameRequired->setText("Required");
           ui->firstNameRequired->show();
           okFirstName=false;
       }
       else//if there is something filled preform the neccessary checks
       {
           ui->firstNameRequired->hide();
           okFirstName=true;
       }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
       if(ui->lastNameInput->text().isEmpty())//check if the last name has been filled or not
       {
           ui->lastNameRequired->setText("Required");
           ui->lastNameRequired->show();
           okLastName=false;
       }
       else
       {
           ui->lastNameRequired->hide();
           okLastName=true;
       }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       if(ui->userNameInput->text().isEmpty())//checks if there is a username has been filled
       {
           ui->userNameRequired->setText("Required");
           ui->userNameRequired->show();
           okUsername = false;
       }
       else
       {
           //username is filled now to check if its avaliable to use
           qDebug()<<"Username field has something in it";
           if(db.userNameAvaliabity(ui->userNameInput->text()))
           {
               okUsername = true;
               ui->userNameRequired->hide();
           }
           else
           {
               okUsername =false;
               qDebug()<<"Username is in use";
               ui->userNameRequired->setText("Username in use");
               ui->userNameRequired->show();
           }

       }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       //password badness

       if(ui->passwordInput->text().isEmpty())
       {
           ui->passwordRequired->setText("Required");
           ui->passwordRequired->show();
       }
       else
       {
           qDebug()<<"Password was entered now to check if the reneter password filled";
           if(ui->renterPasswordInput->text().isEmpty())
           {
               ui->renterPasswordRequired->setText("Please reneter password");
               ui->renterPasswordRequired->show();
           }
           else
           {
               if(ui->passwordInput->text()==ui->renterPasswordInput->text())
               {
                   qDebug()<<"Passwords are a match";
                   ui->passwordRequired->hide();
                   ui->renterPasswordRequired->hide();
                   okPassword=true;

               }
               else
               {
                   ui->renterPasswordRequired->setText("Passwords do not match");
                   ui->renterPasswordRequired->show();
                   ui->passwordRequired->hide();
                   okPassword=false;
               }
           }
       }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// eveything checks out now to actually add to db ///////////////////////////////////////////////////////////
       if(okFirstName==true&&okLastName==true&&okUsername==true&&okPassword==true)
       {
           credsCheck=true;
           db.addUser(ui->userNameInput->text(),ui->firstNameInput->text(),ui->lastNameInput->text(),ui->passwordInput->text(),"",1);
           this->close();
           Login log;
           log.setModal(true);
           log.exec();
       }
       else
       {
           QMessageBox::warning(this,"Warning","Not finished");
           break;
       }
    }
}
