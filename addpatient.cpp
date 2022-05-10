#include "addpatient.h"
#include "ui_addpatient.h"

AddPatient::AddPatient(QString doctor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatient)
{
    ui->setupUi(this);
    doctorUsername = doctor;
    ui->dateEdit->setDate(QDate::currentDate());
    connect(ui->createButton,SIGNAL(clicked()),this,SLOT(createButtonPressed()));


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
