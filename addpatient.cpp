#include "addpatient.h"
#include "ui_addpatient.h"

AddPatient::AddPatient(QString doctor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatient)
{
    ui->setupUi(this);
    doctorUsername = doctor;
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

    QString firstName = ui->firstNameInput->text();
    QString lastName = ui->lastNameInput->text();
    QString age = ui->ageInput->text();
    QString phoneNumber = ui->phoneNumberInput->text();
    QString gender = ui->genderComboBox->currentText();
    QString dob = ui->dateEdit->text();

    if(firstName.isEmpty())
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


    qDebug()<<"Preflight Check for adding a patient to the database";
    qDebug()<<"First Name: "<<firstName;
    qDebug()<<"Last Name: "<<lastName;
    qDebug()<<"Age: "<<age;
    qDebug()<<"Phone Number: "<<phoneNumber;
    qDebug()<<"Gender: "<<gender;
    qDebug()<<"Date of Birth: "<<dob;

    if(firstNameOK==true&&lastNameOK == true)
    {
        db.addPatient(firstName, lastName, age, phoneNumber, gender, dob);
        this->close();
    }


}
