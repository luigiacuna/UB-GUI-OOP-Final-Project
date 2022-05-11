#include "addpatient.h"
#include "ui_addpatient.h"

AddPatient::AddPatient(QString doctor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatient)
{
    ui->setupUi(this);
    doctorUsername = doctor;
    //ui->genderComboBox->setEditable(true);
    ui->dateEdit->setDate(QDate::currentDate());
    connect(ui->createButton,SIGNAL(clicked()),this,SLOT(createButtonPressed()));
    //connect(ui->genderComboBox->lineEdit(), SIGNAL(editingFinished()), SLOT(editingFinished()));


}

AddPatient::~AddPatient()
{
    delete ui;
}

void AddPatient::createButtonPressed()
{
    bool firstNameOK;
    bool lastNameOK;

    if(ui->firstNameInput->text().isEmpty())
    {
        qDebug()<<"first name is empty";
        ui->firstNameLabel->setText("First Name (*)");
        ui->firstNameLabel->setStyleSheet("font-weight: bold;color: red");
        ui->firstNameInput->setPlaceholderText("Cannot be empty");
        firstNameOK=false;
    }
    else
        firstNameOK=true;
    if(ui->lastNameInput->text().isEmpty())
    {
        qDebug()<<"last name is empty";
        ui->lastNameLabel->setText("Last Name (*)");
        ui->lastNameLabel->setStyleSheet("font-weight: bold;color: red");
        ui->lastNameInput->setPlaceholderText("Cannot be empty");
        lastNameOK=false;
    }
    else
        lastNameOK=true;


    /*qDebug()<<"Preflight Check for adding a patient to the database";
    qDebug()<<"First Name: "<<firstName;
    qDebug()<<"Last Name: "<<lastName;
    qDebug()<<"Age: "<<age;
    qDebug()<<"Phone Number: "<<phoneNumber;
    qDebug()<<"Gender: "<<gender;
    qDebug()<<"Date of Birth: "<<dob;*/

    if(firstNameOK==true&&lastNameOK == true)
    {
        addPatient(ui->firstNameInput->text(),
                   ui->lastNameInput->text(),
                   ui->ageInput->text(),
                   ui->phoneNumberInput->text(),
                   ui->genderComboBox->currentText(),
                   ui->dateEdit->text(),
                   ui->ssNumInput->text(),
                   getUserID(doctorUsername));
        this->close();
        EditPatient editPat("");
        editPat.setModal(true);
        editPat.exec();
    }


}

void AddPatient::on_firstNameInput_editingFinished()
{
    QFile txt("./PatientLog.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append);
    QApplication::processEvents();

    QTextStream out(&txt);
    QString fName;
    fName = ui->firstNameInput->text();

    out<<"////////////////////////Patient Log////////////////////////"<<"\n";
    out<<"Patient Name: ";
    out<<fName<<" ";
}

void AddPatient::on_lastNameInput_editingFinished()
{
    QFile txt("./PatientLog.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append);
    QApplication::processEvents();

    QTextStream out(&txt);
    QString lName;
    lName = ui->lastNameInput->text();
    out<<lName<<"\n";
}

void AddPatient::on_ageInput_editingFinished()
{
    QFile txt("./PatientLog.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append);
    QApplication::processEvents();

    QTextStream out(&txt);
    QString age;
    age = ui->ageInput->text();
    out<<"Patient Age: ";
    out<<age<<"\n";
}

void AddPatient::on_phoneNumberInput_editingFinished()
{
    QFile txt("./PatientLog.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append);
    QApplication::processEvents();

    QTextStream out(&txt);
    QString number;
    number = ui->phoneNumberInput->text();
    out<<"Patient Number: ";
    out<<number<<"\n";
}

void AddPatient::on_genderComboBox_textActivated(const QString &arg1)
{
    QFile txt("./PatientLog.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append);
    QApplication::processEvents();

    QTextStream out(&txt);
    QString gender;
    gender = ui->genderComboBox->currentText();
    out<<"Patient Gender: ";
    out<<gender<<"\n";
}

void AddPatient::on_dateEdit_editingFinished()
{
    QFile txt("./PatientLog.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append);
    QApplication::processEvents();

    QTextStream out(&txt);
    QString date;
    date = ui->dateEdit->text();
    out<<"Date: ";
    out<<date<<"\n";
}

void AddPatient::on_ssNumInput_editingFinished()
{
    QFile txt("./PatientLog.txt");
    txt.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append);
    QApplication::processEvents();

    QTextStream out(&txt);
    QString socialS;
    socialS = ui->ssNumInput->text();
    out<<"Patient Social Security: ";
    out<<socialS<<"\n";

    out<<"////////////////////////Patient Log////////////////////////"<<"\n"<<"\n";
}


