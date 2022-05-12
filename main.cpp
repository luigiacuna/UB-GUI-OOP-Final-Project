#include "Login.h"

#include <QApplication>
//Testing if working on git hub April 24 2022


int main(int argc, char *argv[])
{
    //starting the database at main to prevent connection duplication
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");//XAMPS Username
    //db.setDatabaseName("adminv2.0");//Josiah Login
    db.setDatabaseName("final");

    if(!db.open())
    {
        qDebug()<<"Database not open";
    }
    else
    {
        qDebug()<<"Connection Successfull at newUser Class";
    }
    //for demo purposes only


    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}
