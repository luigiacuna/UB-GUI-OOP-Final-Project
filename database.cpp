#include "database.h"

Database::Database()
{
    /*The database is not opened here because whenever a query needs to be executed the constructor will always run before the called function and reopening the database
    *reopening the database here will cause duplicate connctions in which two senarios will happen
    *1. All queries that have will be executed will not occur
    *2. Any reopening of the database will force the old connection to close and be replaced by the new connection but this will present a warning to the programer and may cause memory leaks
    *Only quries will be done on need to run basis*/
}

bool Database::userNameAvaliabity(QString username)
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

bool Database::addUser(QString username, QString firstName, QString lastName, QString password, QString type)
{
    //this function is executed by the newUser class and is the final query that is done in this class
    //this is run when all checks by the newUser class has passed and all parameters
    //passed in are valid and ready to be passed in the database itself

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

    if(qry.exec())
    {
        qDebug()<<"New User added.";
        return true;

    }
    else
    {
        qDebug()<<"Insert failed";
        return false;
    }
}

bool Database::checkCredentials(QString username, QString password)
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

QString Database::getRole(QString username)
{
    //Returns the role of the user that is currently logged in. This function is called from the openRole() function in Login Class
    QSqlQuery qry;
    qry.prepare("SELECT type FROM users WHERE username=:use;");
    qry.bindValue(":use",username);
    qry.exec();
    qry.next();
    return qry.value(0).toString();//if its only one thing that the query produces just call next() without using a while loop
}


QSqlQueryModel* Database::adminTable(int num)//updates the two table widgets in the admin window
{
    if(num == 1)
    {
        QSqlQuery *qry = new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("SELECT username FROM users;");
        qry->exec();
        model->setQuery(std::move(*qry));
        return model;
    }
    else if(num == 2)
    {
        QSqlQuery *qry = new QSqlQuery();
        QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("SELECT fname,lname,type FROM users;");
        qry->exec();
        model->setQuery(std::move(*qry));
        return model;
    }

}

void Database::resetPassword(QString)
{
    QSqlQuery qry;
    qry.prepare("UPDATE users SET password=:? WHERE username=:?");
}

void Database::deleteUser(QString username)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM users WHERE username=:use;");
    qry.bindValue(":use",username);
    qry.exec();
}
