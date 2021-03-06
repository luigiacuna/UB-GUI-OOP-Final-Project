#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

#include <iostream>

using namespace std;


class Database
{
public:
    Database();
    bool userNameAvaliabity(QString);//used in the NewUser Class and login class
    bool addUser(int,QString,QString,QString,QString,QString,int);//NewUser Class
    bool checkCredentials(QString, QString);//used in Login Class
    QString getRole(QString);//used in Login Class
    QSqlQueryModel* adminTable(int); //admin window to show username
    void resetPassword(QString, QString);//reset user password at the admin window
    void deleteUser(QString);
    void addPatient(QString,QString,QString,QString,QString,QString,QString,QString);
    QStringList getUserInformation(QString);
    QString getPassword(QString);
    QSqlQueryModel *medList();
    void addMeds(QString);
    QStringList listAvaliableMeds();//a check to see if a med that is going to be added doesn't exist already
    QSqlQueryModel* showAvaliableMeds();//show on the table what are avaliable meds
    void removeMed(QString);//remove seleted med
    QStringList listAvaliableNurses();
    QString getFullName(QString,QString);
    QString getUserID(QString);
    QStringList listAvaliablePatients();
    QStringList selectedPatientInfo(QString);
    QStringList listAvaliableDoctors();
    void updatePatient(QString, QString, QString, QString, QString,QString, QString, QString, QString);
    QSqlQueryModel* scheduleTable(); //shows schedule in nurse view
    void addSchedule(QString,QString,QString,QString,QString,QString,QString,QString,QString);
    QList<int> medChart();
    QStringList medCategory();
    QSqlQueryModel *showSchedule(QString,int);
    QSqlQueryModel *showScheduleID(QString, int);
    void removeSchedule(QString);

protected:
    int choice = 1;
    int choice2 = 2;

};

#endif // DATABASE_H
