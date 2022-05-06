#include "database.h"

Database::Database()
{
    /*The database is not opened here because whenever a query needs to be executed the constructor will always run before the called function and reopening the database
    *reopening the database here will cause duplicate connctions in which two senarios will happen
    *1. All queries that have will be executed will not occur
    *2. Any reopening of the database will force the old connection to close and be replaced by the new connection but this will present a warning to the programer and may cause memory leaks
    *Only quries will be done on need to run basis*/
}

bool Database::userNameAvaliabity(QString username)//get function
{
    //used in the NewUser Classn and Login this will check if the username inputted by the user
    //is avalibale for use in the database as a valid username
    QSqlQuery qry;
    QStringList userNameList;
    qry.prepare("SELECT username FROM users;");
    if(qry.exec())
    {
        qDebug()<<"Getting the list of usernames";
    }
    else
    {
        qDebug()<<"Could not find username list";
        qDebug()<<"Database error: "<<qry.lastError();
    }
    //grab all the avaliable usernames and put them in a string list for comparison
    while(qry.next())
        userNameList<<qry.value(0).toString();
    qDebug()<<"Current Usernames that are available: "<<userNameList;
    if(userNameList.contains(username))
    {
        qDebug()<<username<<" has been in found in the users list cannot add";
        return false;
    }
    else
    {
        qDebug()<<username<<" is a valid username";
        return true;
    }


}

bool Database::addUser(int id,QString username, QString firstName, QString lastName, QString password, QString type, int choice)//setfunction
{
    //this function is executed by the newUser class and is the final query that is done in this class
    //this is run when all checks by the newUser class has passed and all parameters
    //passed in are valid and ready to be passed in the database itself

    //UPDATE April 28 2022 - going to add another paramter to add an update query since the original add function does the same exact same thing code wise
    //1 will be for adding user and 2 will be updating user records

    QSqlQuery qry;
    //need to get a count of how many users are avaliable to add the correct count to the database
    qry.prepare("SELECT * FROM users;");
    qry.exec();
    int usersCount=0;
    while(qry.next())
    {
       usersCount=qry.value(0).toInt();
    }
    qDebug()<<"Number of users in the database: "<<usersCount;

    //Everything checksout now to actually add to the database
    if(choice == 1)//used at the newUser class
    {
         qry.prepare("INSERT INTO users(id,username,fname,lname,password,type) VALUES(?,?,?,?,?,?);");
         qry.addBindValue(usersCount+1);
         qry.addBindValue(username);
         qry.addBindValue(firstName);
         qry.addBindValue(lastName);
         qry.addBindValue(password);
         if(type=="")
             qry.addBindValue("nurse");
         else
             qry.addBindValue(type);
    }
    else if(choice == 2)//used by the editUser Class
    {
        qDebug()<<type;
        //QString idToString = id
        qry.prepare("UPDATE users SET fname=:first, lname=:last, username=:use, type=:tipo WHERE id=:intNum;");
        qry.bindValue(":first",firstName);
        qry.bindValue(":last",lastName);
        qry.bindValue(":use",username);
        qry.bindValue(":tipo",type);
        qry.bindValue(":intNum",id);
    }

    if(qry.exec())
    {
        qDebug()<<"New User added/updated.";
        return true;

    }
    else
    {
        qDebug()<<"Insert/Updated failed";
        return false;
    }
}

bool Database::checkCredentials(QString username, QString password)//get funtion
{
    //This function is used in the login class
    //checking if username is avaliable going to use userNameAvaliabity() since it can already do that but however use false as the answer
    qDebug()<<"Starting checkCredentials()";
    if(!userNameAvaliabity(username))
    {
        //looking for a false return means that the username is found and now to check if the password matches with the username
        QSqlQuery qry;
        QString dbPassword;
        qry.prepare("SELECT password FROM users WHERE username=:use;");//since the username is correct use a query to extract the password
        qry.bindValue(":use",username);
        qry.exec();
        while(qry.next())
            dbPassword=qry.value(0).toString();//and pass it to QString for validiation
        qDebug()<<dbPassword;
        if(dbPassword==password)//said validation
        {
            qDebug()<<"Its Gucci";
            return true;//everything is correct allow the user to login
        }
        else
        {
            qDebug()<<"Its not gucci lmao";
            return false;//nope incorrect credentials go and complain to the user
        }
    }
    else
    {
        qDebug()<<"It got here";
        return false;
    }
}

QString Database::getRole(QString username)//getfuntion
{
    //Returns the role of the user that is currently logged in. This function is called from the openRole() function in Login Class
    QSqlQuery qry;
    qry.prepare("SELECT role FROM users WHERE username=:use;");
    qry.bindValue(":use",username);
    qry.exec();
    qry.next();
    return qry.value(0).toString();//if its only one thing that the query produces just call next() without using a while loop
}


QSqlQueryModel* Database::adminTable(int num)//updates the two table widgets in the admin window getfuntion
{
    if(num == 1)
    {
        QSqlQuery *qry = new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("SELECT id FROM users ORDER BY id ASC;");
        qry->exec();
        model->setQuery(std::move(*qry));
        return model;
    }
    else if(num == 2)
    {
        QSqlQuery *qry = new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        //qry->prepare("SELECT fname,lname,type,username,password FROM users;"); //dummy db query
        qry->prepare("SELECT username, role FROM users");
        qry->exec();
        model->setQuery(std::move(*qry));
        return model;
    }

}

void Database::resetPassword(QString id, QString newPassword)//setfunction
{
    QSqlQuery qry;
    qry.prepare("UPDATE users SET password=:pass WHERE id=:id");
    qry.bindValue(":pass",newPassword);
    qry.bindValue(":id",id);
    if(qry.exec())
    {
        qDebug()<<"Passwords has been reset";
    }
    else
    {
        qDebug()<<qry.lastError().text();
    }

}

void Database::deleteUser(QString username)
{
    QSqlQuery qry;
    //first get the role of the user plays in the database
    qry.prepare("SELECT role FROM users WHERE id=:id");
    qry.bindValue(":id",username);

    //delete the user from the table that it belongs to either nurse/doctor/admin

    //delete the user from the user table
    qry.prepare("DELETE FROM users WHERE id=:id;");
    qry.bindValue(":id",username);
    qry.exec();
}

QStringList Database::getUserInformation(QString username)
{
    QStringList data;
    QSqlQuery qry;
    QString roleCheck;

    //first to grab the role to understand which table information to grab and present to the user
    qry.prepare("SELECT role FROM users WHERE id=:id");
    qry.bindValue(":id",username);
    qry.exec();
    qry.next();
    roleCheck = qry.value(0).toString();
    qry.clear();
    qDebug()<<"Username value comming in is "<<username;
    qDebug()<<"Role Check value is: "<<roleCheck;

    //I wanted originally to use bind value in the FROM area of the query but the queryt would bever work so this if else statement will decide which one will execute based of role Check
    //firstly grab the first name
    if(roleCheck == "admin")
    {
        qry.prepare("SELECT firstname FROM admin WHERE id=:id");
        qry.bindValue(":id",username);
        qry.exec();
        qry.next();
        data<<qry.value(0).toString();
        qry.clear();
    }
    else if (roleCheck == "doctor")
    {
        qry.prepare("SELECT firstname FROM doctor WHERE id=:id");
        qry.bindValue(":id",username);
        qry.exec();
        qry.next();
        data<<qry.value(0).toString();
        qry.clear();
    }
    else if (roleCheck == "nurse")
    {
        qry.prepare("SELECT firstname FROM nurse WHERE id=:id");
        qry.bindValue(":id",username);
        qry.exec();
        qry.next();
        data<<qry.value(0).toString();
        qry.clear();
    }
    //now get the lastname

    if(roleCheck == "admin")
    {
        qry.prepare("SELECT lastname FROM admin WHERE id=:id");
        qry.bindValue(":id",username);
        qry.exec();
        qry.next();
        data<<qry.value(0).toString();
        qry.clear();
    }
    else if (roleCheck == "doctor")
    {
        qry.prepare("SELECT lastname FROM doctor WHERE id=:id");
        qry.bindValue(":id",username);
        qry.exec();
        qry.next();
        data<<qry.value(0).toString();
        qry.clear();
    }
    else if (roleCheck == "nurse")
    {
        qry.prepare("SELECT lastname FROM nurse WHERE id=:id");
        qry.bindValue(":id",username);
        qry.exec();
        qry.next();
        data<<qry.value(0).toString();
        qry.clear();
    }
    //everything else that is needed comes from the users table
    qry.prepare("SELECT role FROM users WHERE id=:id");
    qry.bindValue(":id",username);
    qry.exec();
    while(qry.next())
        data<<qry.value(0).toString();
    qry.clear();

    qry.prepare("SELECT username FROM users WHERE id=:id");
    qry.bindValue(":id",username);
    qry.exec();
    while(qry.next())
        data<<qry.value(0).toString();
    qry.clear();
    return data;

}

QString Database::getPassword(QString username)//used in the editUser Class to grab the current User selected's password
{
    QSqlQuery qry;
    qry.prepare("SELECT password FROM users WHERE username=:use");
    qry.bindValue(":use",username);
    qry.exec();
    qry.next();
    return qry.value(0).toString();

}

void Database::addMeds(QString medicine)
{
    //create the med_code value
    QString medCode = medicine.chopped(3);
    qDebug()<<"The med code that will be created is "<<medCode<<" which comes from "<<medicine;

    //actually push the values with an insert query
    QSqlQuery qry;
    qry.prepare("INSERT INTO medicine(med_id,med_name) VALUES(?,?);");
    qry.addBindValue(medCode);
    qry.addBindValue(medicine);
    if(qry.exec())
    {
        qDebug()<<"Medicine was added";
    }
    else
    {
        qDebug()<<qry.lastError().text();
    }
}

QStringList Database::listAvaliableMeds()
{
    QStringList data;
    QSqlQuery qry;
    qry.prepare("SELECT med_name FROM medicine");
    qry.exec();
    while(qry.next())
        data<<qry.value(0).toString();
    return data;
}

QSqlQueryModel* Database::showAvaliableMeds()
{
    QSqlQuery *qry = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    qry->prepare("SELECT med_name FROM medicine");
    qry->exec();
    model->setQuery(std::move(*qry));
    return model;
}

void Database::removeMed(QString med)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM medicine WHERE med_name=:med");
    qry.bindValue(":med",med);
    qry.exec();
}
