#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    //connects
    connect(ui->onOkButton,SIGNAL(clicked()),this,SLOT(onOK())); //check login credentials and stuff
    connect(ui->newUser,SIGNAL(clicked()),this,SLOT(createNewUser())); //create a new user and stuff

}

Login::~Login()
{
    delete ui;
}

void Login::onOK()//works like a set function
{

    //using a nested if to check one for a critera then the other if it checks out
    if(ui->userNameInput->text().isEmpty()) //first it will check if the username is empty here
    {
        qDebug()<<"Nothing has been filled in";
        ui->incorrectAnything->hide();
        ui->userNameError->setText("Required");
        ui->userNameError->show();
        ui->passwordError->setText("Required");
        ui->passwordError->show();
    }
    else//if the username has been filled in
    {
        if(ui->passwordInput->text().isEmpty())//check if the password field is empty
        {
            qDebug()<<"Username has been filled in";
            qDebug()<<"No Password has been entered tho ";
            ui->incorrectAnything->setText("Incorrect Username and Password");
            ui->incorrectAnything->show();
            ui->userNameError->hide();
            ui->passwordError->hide();
        }
        else//it has something and now to check if its valid credentials or not
        {
           if(db.checkCredentials(ui->userNameInput->text(),ui->passwordInput->text()))
           {
               ui->incorrectAnything->setText("Logged In");
               ui->incorrectAnything->show();
               ui->userNameError->hide();
               ui->passwordError->hide();
               openRole(ui->userNameInput->text());
           }
        }
    }
        /*potencial ideas
         * put all database queries in its own class so not to clutter up the rest of classes -> this has been implement 4/20 blaze it day
         * if a db query is needed just create a function and call it within the class that needs it
         * one rule if a function is created add a comment stating its purpose and where it has been implemented
         * so to not get confused later down the road
         * UPDATE: actually had to go through with this cause my other class will not play nice and like before it
         * makes the code so much cleaner*/

        //there was one point an admin button to allow admins to access but i decided otherwise that it was double work and work it in the regular process

    //using a database class to seprate all the queries just cause more issues than answers so all queries happen in classes it needs to happen-> got it fixed now
}

void Login::createNewUser()//this can be probably be inhereitented since the doctor will have to be able to do this for patients
{
    //opens the newuser window to allow new users to create users neccessary?? not sure not will implement just in case
    this->close();
    NewUser newUser;
    newUser.setModal(true);
    newUser.exec();

    //cause a potencial memory leak due to restablishing a connection to the db need a way to fix this
    /*QSqlDatabasePrivate::removeDatabase: connection 'qt_sql_default_connection' is still in use, all queries will cease to work.
    QSqlDatabasePrivate::addDatabase: duplicate connection name 'qt_sql_default_connection', old connection removed.*/
    //April 18 2022 database was fixed until i realize it was still broken
    //April 20 2022 fixed all database issues for sure now *knock wood*
}

void Login::openRole(QString username)
{
    //the purpose of this function is to determine which part of the application will be opened based on the role of the user that has logged in
    //it will offsite db query grab the role and if it matches any of the three roles (doctor, nurse, admin) it will open that particular window and proceeed with the program
    if(db.getRole(username)=="admin")
    {
        qDebug()<<"The big boss has logged in";
        this->close();
        AdminWindow *adminWin= new AdminWindow(ui->userNameInput->text(),"admin");
        adminWin->show();
    }
    else if(db.getRole(username)=="nurse")
    {
        qDebug()<<"a peasant nurse has logged in";
        this->close();
        NurseView *nurse= new NurseView();
        nurse->show();
    }
    else if(db.getRole(username)=="doctor")
    {
        qDebug()<<"mid tier nugget (doctor) has logged in";
        this->close();
        DoctorView *doc= new DoctorView(ui->userNameInput->text(),"doctor");
        doc->show();
    }
    else
    {
        qDebug()<<"It should not get here at all all checks has passed validation and inserted in the database with no null values";
    }
}

