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
    bool addUser(int,QString,QString,QString,QString,QString, int);//NewUser Class
    bool checkCredentials(QString, QString);//used in Login Class
    QString getRole(QString);//used in Login Class
    QSqlQueryModel* adminTable(int); //admin window to show username
    void resetPassword(QString);//reset user password at the admin window
    void deleteUser(QString);
    QStringList getUserInformation(QString);
    QString getPassword(QString);//get the password for a specfic user used in the edit user
};

#endif // DATABASE_H
