#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>


class Database
{
public:
    Database();
    bool userNameAvaliabity(QString);//used in the NewUser Class and login class
    bool addUser(QString,QString,QString,QString,QString);//NewUser Class
    bool checkCredentials(QString, QString);//used in Login Class
    QString getRole(QString);//used in Login Class
    QSqlQueryModel* adminTable(int); //admin window to show username
    void resetPassword(QString);//reset user password at the admin window
};

#endif // DATABASE_H
