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
    if(ui->firstNameInput->text().isEmpty())
    {
        qDebug()<<"first name is empty";
        ui->firstNameLabel->setText("First Name (*)");
        ui->firstNameLabel->setStyleSheet("font-weight: bold;color: red");
        firstNameOK=false;
    }
    else
        firstNameOK=true;
    if(ui->lastNameInput->text().isEmpty())
    {
        qDebug()<<"last name is empty";
        ui->lastNameLabel->setText("Last Name (*)");
        ui->lastNameLabel->setStyleSheet("font-weight: bold;color: red");
        lastNameOK=false;
    }
    else
        lastNameOK=true;


    qDebug()<<"Preflight Check for adding a patient to the database";
    qDebug()<<"First Name: "<<ui->firstNameInput->text();
    qDebug()<<"Last Name: "<<ui->lastNameInput->text();
    qDebug()<<"Age: "<<ui->ageInput->text();
    qDebug()<<"Phone Number: "<<ui->phoneNumberInput->text();
    qDebug()<<"Gender: "<<ui->genderComboBox->currentText();
    qDebug()<<"Date of Birth: "<<ui->dateEdit->text();

    if(firstNameOK==true&&lastNameOK == true)
    {

    }
}
