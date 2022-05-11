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

    //qDebug paramter check
    qDebug()<<"ID number to be assigned: "<<usersCount+1;
    qDebug()<<"Username: "<<username;
    qDebug()<<"First Name: "<<firstName;
    qDebug()<<"Last Name: "<<lastName;
    qDebug()<<"Password: "<<password;
    qDebug()<<"Role to be assigned: "<<type;

    //Sheeeeeeeeeeeeeeeeeeeeeeeeesh
        if(choice == 1)//used at the newUser class
        {
            //Made these two queries because i wanted to see if i add a doctor if his information will show up on the admin table
            qry.prepare("INSERT INTO users(id,username,password,role) VALUES(:id,:username,:password,:role);");
            qry.addBindValue(usersCount+1);
            qry.bindValue(":username", username);
            qry.bindValue(":password", password);
            //small change here it add correctly and everything just the role is case-sensitive and hold certain spelling so this quick if else will handle it
            if(type == "Administrator")
                qry.bindValue(":role", "admin");
            else if(type == "Doctor")
                qry.bindValue(":role", "doctor");
            else if(type == "Nurse")
                qry.bindValue(":role", "nurse");

            if(qry.exec())
            {
                qDebug()<<"Insert at users table success";
            }
            else
            {
                qDebug()<<"Failure to add to users table first "<<qry.lastError().text();
            }
            qry.clear();

            if(type == "Doctor")
            {
                qry.prepare("INSERT INTO doctor(id, username, firstname, lastname) VALUES(:id, :username, :firstname, :lastname);");
                qry.addBindValue(usersCount+1);
                qry.bindValue(":username", username);
                qry.bindValue(":firstname", firstName);
                qry.bindValue(":lastname", lastName);
                if(qry.exec())
                {
                    qDebug()<<"Insert at doctor table success";
                }
                else
                {
                    qDebug()<<"Failure to add user to the doctor table "<<qry.lastError().text();
                }
                qry.clear();
            }
            else if(type == "Administrator")
            {
                qry.prepare("INSERT INTO admin(id, username, firstname, lastname) VALUES(:id, :username, :firstname, :lastname);");
                qry.addBindValue(usersCount+1);
                qry.bindValue(":username", username);
                qry.bindValue(":firstname", firstName);
                qry.bindValue(":lastname", lastName);
                if(qry.exec())
                {
                    qDebug()<<"Insert at admin table success";
                }
                else
                {
                    qDebug()<<"Failure to add user to the admin table "<<qry.lastError().text();
                }
                qry.clear();
            }
            else if(type == "Nurse")
            {
                qry.prepare("INSERT INTO nurse(id, username, firstname, lastname) VALUES(:id, :username, :firstname, :lastname);");
                qry.addBindValue(usersCount+1);
                qry.bindValue(":username", username);
                qry.bindValue(":firstname", firstName);
                qry.bindValue(":lastname", lastName);
                if(qry.exec())
                {
                    qDebug()<<"Insert at nurse table success";
                }
                else
                {
                    qDebug()<<"Failure to add user to the nurse table "<<qry.lastError().text();
                }
                qry.clear();
            }

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
            qDebug()<<qry.lastError().text();
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

void Database::resetPassword(QString newPassword, QString id)//setfunction
{
    try
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
            throw 0;
            qDebug()<<qry.lastError().text();
        }
    }
    catch(int x)
    {
        qDebug()<<"ERROR CODE "<< x << " Query did not execute";
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

void Database::addPatient(QString firstName, QString lastName, QString age, QString phoneNumber, QString gender, QString dob, QString ss,QString doctor)
{
    qDebug()<<"Doctor parameter: "<<doctor;
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM patients;");
    qry.exec();
    qry.next();
    QString count = qry.value(0).toString();
    //now actually combine them with the first initial of firstname, lastname and the current count
    QString patientID = firstName.left(0)+lastName.left(0)+count;//use this to bind the value to id
    qry.clear();

    //QSqlQuery qry;
    qry.prepare("INSERT INTO patients(patient_id, firstName, lastName, age, phonenumber, gender, dob,socialsecruity,doctor_id)"
                " VALUES(:id, :firstName, :lastName, :age, :phonenumber, :gender, :dob, :ss, :doc);");
    qry.bindValue(":id", patientID);
    qry.bindValue(":firstName",firstName);
    qry.bindValue(":lastName",lastName);
    qry.bindValue(":age",age);
    qry.bindValue(":phonenumber",phoneNumber);
    qry.bindValue(":gender",gender);
    qry.bindValue(":dob",dob);
    qry.bindValue(":ss",ss);
    qry.bindValue(":doc",doctor);
    if(!qry.exec())
    {
        qDebug()<<qry.lastError().text();
    }
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

QString Database::getPassword(QString username)
{
    QSqlQuery qry;
    qry.prepare("SELECT password FROM users WHERE username=:use");
    qry.bindValue(":use",username);
    qry.exec();
    qry.next();
    return qry.value(0).toString();

}

QSqlQueryModel *Database::medList()
{
    QSqlQuery *qry = new QSqlQuery();
    qry->prepare("SELECT med_name FROM medicine");
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(std::move(*qry));
    return model;
}

void Database::addMeds(QString medicine)
{
    //create the med_code value from a count
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM medicine");
    qry.exec();
    int medCount=0;
    while(qry.next())
    {
        medCount=qry.value(0).toInt();
    }
    //actually push the values with an insert query
    qry.prepare("INSERT INTO medicine(med_id,med_name) VALUES(?,?);");
    qry.addBindValue(medCount);
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
    qry.prepare("SELECT med_id, med_name FROM medicine");
    qry.exec();
    while(qry.next())
        data<<qry.value(0).toString()+" "+qry.value(1).toString();
    return data;
}

QSqlQueryModel *Database::showAvaliableMeds()
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

QStringList Database::listAvaliableNurses()
{
    //This will list the avalibale nurses that will be shown when adding a patient
    //since in the database nurse table the first name and last name is seperated this will need to be combined somehow
    QSqlQuery qry;
    QStringList data;
    qry.prepare("SELECT id, firstname,lastname FROM nurse");//only grabs whatever was called first and is able to pass in to a StringList
    qry.exec();
    while(qry.next())
        data<<qry.value(0).toString()+" "+qry.value(1).toString() + " " + qry.value(2).toString();
    qDebug()<<"List of Avaliable Nurses: "<<data;
    return data;
}

QString Database::getFullName(QString username, QString role)
{
    QSqlQuery qry;
    if(role == "admin")
    {
        qry.prepare("SELECT firstname,lastname FROM admin WHERE username=:use ");
        qry.addBindValue(role);
        qry.bindValue(":use",username);
        qry.exec();
        qry.next();
        return qry.value(0).toString()+" "+qry.value(1).toString();
    }
    else if(role == "nurse")
    {
        qry.prepare("SELECT firstname,lastname FROM nurse WHERE username=:use ");
        qry.addBindValue(role);
        qry.bindValue(":use",username);
        qry.exec();
        qry.next();
        return qry.value(0).toString()+" "+qry.value(1).toString();
    }
    else if(role == "doctor")
    {
        qry.prepare("SELECT firstname,lastname FROM doctor WHERE username=:use ");
        qry.addBindValue(role);
        qry.bindValue(":use",username);
        qry.exec();
        qry.next();
        return qry.value(0).toString()+" "+qry.value(1).toString();
    }
}

QString Database::getUserID(QString username)
{
    QSqlQuery qry;
    qry.prepare("SELECT id FROM users WHERE username=:use");
    qry.bindValue(":use",username);
    qry.exec();
    qry.next();
    return qry.value(0).toString();
}

QStringList Database::listAvaliablePatients()
{
    QStringList data;
    QSqlQuery qry;
    qry.prepare("SELECT patient_id, lastname,firstname FROM patients;");
    qry.exec();
    while(qry.next())
        data<<qry.value(0).toString()+" "+qry.value(1).toString()+", "+qry.value(2).toString();
    return data;
}

QStringList Database::selectedPatientInfo(QString patientID)
{
    qDebug()<<"Patient ID being pushed in is: "<<patientID;
    QStringList data;
    QSqlQuery qry;
    qry.prepare("SELECT firstname,lastName,age,phonenumber,gender,dob,socialsecruity FROM patients WHERE patient_id=:id;");
    qry.bindValue(":id",patientID);
    qry.exec();
    qry.next();
    data<<qry.value(0).toString()<<qry.value(1).toString()<<qry.value(2).toString()<<qry.value(3).toString()<<qry.value(4).toString()<<qry.value(5).toString()<<qry.value(6).toString();
    qry.clear();

    qry.prepare("SELECT doctor.id, doctor.firstname, doctor.lastname FROM doctor WHERE id IN (SELECT doctor_id FROM patients WHERE patient_id=:id);");
    qry.bindValue(":id",patientID);
    qry.exec();
    qry.next();
    data<<qry.value(0).toString()+" "+qry.value(1).toString()+" "+qry.value(2).toString();
    qDebug()<<"selected Patient Data: "<<data;
    return data;
}

QStringList Database::listAvaliableDoctors()
{
    QSqlQuery qry;
    QStringList data;
    qry.prepare("SELECT id, firstname,lastname FROM doctor");//only grabs whatever was called first and is able to pass in to a StringList
    qry.exec();
    while(qry.next())
        data<<qry.value(0).toString()+" "+qry.value(1).toString() + " " + qry.value(2).toString();
    qDebug()<<"List of Avaliable Nurses: "<<data;
    return data;
}

void Database::updatePatient(QString id, QString firstname, QString lastname, QString age, QString phone, QString gender, QString dob, QString ss, QString doc_id)
{
    QSqlQuery qry;
    //qry.prepare("UPDATE users SET password=:pass WHERE id=:id");
    qry.prepare("UPDATE patients SET firstName=:first,"
                "                    lastName=:last,"
                "                    age=:num,"
                "                    phonenumber=:phonenum,"
                "                    gender=:identifier,"
                "                    dob=:birth,"
                "                    socialsecruity=:ssNum,"
                "                    doctor_id=:doc WHERE patient_id=:id");
    qry.bindValue(":first",firstname);
    qry.bindValue(":last",lastname);
    qry.bindValue(":num",age);
    qry.bindValue(":phonenum",phone);
    qry.bindValue(":identifier",gender);
    qry.bindValue(":birth",dob);
    qry.bindValue(":ssNum",ss);
    qry.bindValue(":doc",doc_id);
    qry.bindValue(":id",id);
    if(qry.exec())
    {
        qDebug()<<"Patient Data successfully updated";
    }
    else
    {
        qDebug()<<qry.lastError().text();
    }
}

QSqlQueryModel *Database::scheduleTable()
{
    QSqlQuery *qry = new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qry->prepare("SELECT schedule_id, patient_id, med_id, dosage_in_num, dosage_units, date_start, date_end FROM schedule;");
    qry->exec();
    model->setQuery(std::move(*qry));
    return model;
}

void Database::addSchedule(QString patientID, QString medID, QString dosageNum, QString dosageUnit, QString dateStart, QString dateEnd, QString  nurseID, QString intervalNum, QString intervalUnit)
{
    QSqlQuery qry;
    //prepare the schedule id that will be created
    qry.prepare("SELECT COUNT(*) FROM schedule");
    qry.exec();
    qry.next();
    int scheduleCount = qry.value(0).toInt();
    qDebug()<<"Current Amount of schedules overall: "<<scheduleCount;
    qry.clear();
    //now to push the apporiate data into the db
    qry.prepare("INSERT INTO schedule (schedule_id,patient_id,med_id,dosage_in_num,dosage_units,date_start,date_end,nurse_id,interval_in_num,interval_in_units)"
                "VALUES (:sid,:pid,:mid,:dosageNum,:dosageUnits,:start,:end,:nid,:intervalNum,:intervalUnits);");
    qry.bindValue(":sid",scheduleCount);
    qry.bindValue(":pid",patientID);
    qry.bindValue(":mid",medID);
    qry.bindValue(":dosageNum",dosageNum);
    qry.bindValue(":dosageUnits",dosageUnit);
    qry.bindValue(":start",dateStart);
    qry.bindValue(":end",dateEnd);
    qry.bindValue(":nid",nurseID);
    qry.bindValue(":intervalNum",intervalNum);
    qry.bindValue(":intervalUnits",intervalUnit);
    if(qry.exec())
        qDebug()<<"Schedule successfully added";
    else
        qDebug()<<"Insert Schedule error: "<<qry.lastError().text();



}

QString Database::medChart()
{
    QSqlQuery qry;
    qry.prepare("SELECT med_id, COUNT(med_id) FROM schedule GROUP BY med_id;");
    qry.exec();
    qry.next();

    return qry.value(0).toString();
}

QStringList Database::medCategory()
{
    QSqlQuery qry;
    QStringList data;
    qry.prepare("SELECT med_name FROM medicine");
    qry.exec();
    while(qry.next())
    {
        data<<qry.value(0).toStringList();
    }
    return data;
}
