#include "editpatient.h"
#include "ui_editpatient.h"

EditPatient::EditPatient(QString patient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPatient)
{
    ui->setupUi(this);
    ui->dobEdit->setDate(QDate::currentDate());
    //pushing items that are already established in the database
    ui->assignedNurseComboBox->addItems(listAvaliableNurses());
    ui->medComboBox->addItems(listAvaliableMeds());
    ui->medComboBox->addItem("Add Medicine");
    //filling the patient combo box with the avaliable patients that have been created
    ui->patientComboBox->addItem("Select a patient");
    ui->patientComboBox->addItems(listAvaliablePatients());//to be grabbed from the patient data portion need to create db function
    ui->doctorComboBox->addItems(listAvaliableDoctors());
    if(patient == "")//disbale all buttons at startup if no patient is passed in
    {
        ui->updateButton->setEnabled(false);
        ui->firstNameEdit->setEnabled(false);
        ui->lastNameEdit->setEnabled(false);
        ui->ageInput->setEnabled(false);
        ui->phoneNumberEdit->setEnabled(false);
        ui->genderComboBox->setEnabled(false);
        ui->dobEdit->setEnabled(false);
        ui->socialSecurityNumberInput->setEnabled(false);
        ui->doctorComboBox->setEnabled(false);
        ui->updateButton->setEnabled(false);
        ui->doctorComboBox->setCurrentIndex(-1);

        //disabling the add schedling buttons
        ui->assignedNurseComboBox->setCurrentIndex(-1);
        ui->assignedNurseComboBox->setEnabled(false);
        ui->medComboBox->setCurrentIndex(-1);
        ui->medComboBox->setEnabled(false);
        ui->dosageValueInNum->setEnabled(false);
        ui->dosageValueInUnits->setEnabled(false);
        ui->intervaValueNum->setEnabled(false);
        ui->intervalValueComboBox->setCurrentIndex(-1);
        ui->intervalValueComboBox->setEnabled(false);
        ui->dateBeginLabel_2->setEnabled(false);
        ui->dateEndInput->setEnabled(false);
        ui->addToSchedule->setEnabled(false);
        ui->removeFromSchedule->setEnabled(false);


    }
    connect(ui->updateButton,SIGNAL(clicked()),this,SLOT(updateButtonPressed()));
}

EditPatient::~EditPatient()
{
    delete ui;
}

void EditPatient::updateButtonPressed()
{
    qDebug()<<"Update button has been pressed";
    bool firstNameOK;
    bool lastNameOK;
    //now to check if the main stuff is not empty by chance
    if(ui->firstNameEdit->text().isEmpty())
    {
        ui->firstNameEdit->setPlaceholderText("Cannot be empty");
        ui->firstNameLabel->setText("First Name (*)");
        ui->firstNameLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->firstNameEdit->setPlaceholderText("");
        ui->firstNameLabel->setText("First Name");
        ui->firstNameLabel->setStyleSheet("font-weight:regular;color:black;");
        firstNameOK = true;
    }
    if(ui->lastNameEdit->text().isEmpty())
    {
        ui->lastNameEdit->setPlaceholderText("Cannot be empty");
        ui->lastNameLabel->setText("First Name (*)");
        ui->lastNameLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->lastNameEdit->setPlaceholderText("");
        ui->lastNameLabel->setText("First Name");
        ui->lastNameLabel->setStyleSheet("font-weight:regular;color:black;");
        lastNameOK = true;
    }


    if(firstNameOK == true && lastNameOK == true)
    {
        QString patientID = ui->patientComboBox->currentText().split(" ").at(0);//for the patient id to be correctly matched
        QString doctorID = ui->doctorComboBox->currentText().split(" ").at(0);
        updatePatient(patientID,ui->firstNameEdit->text(),ui->lastNameEdit->text(),ui->ageInput->text(),ui->phoneNumberEdit->text(),ui->genderComboBox->currentText(),ui->dobEdit->text(),ui->socialSecurityNumberInput->text(),doctorID);
    }


}

void EditPatient::on_medComboBox_textActivated(const QString &arg1)
{
    //allows doctors to quiclky add medicine albeilt this quick action still have to follow the same rules as addMedicine class
        if(arg1 == "Add Medicine")
        {
           qDebug()<<"yah this i be looking for";
           bool ok;
           //QString addMedMsg = QInputDialog::getText(this,"Add Medicine","Add a medicine not on the list",QLineEdit::Normal,QDir::home().dirName(),&ok);
           QString addMedMsg = QInputDialog::getText(this,"Add Medicine","Add a medicine not on the list",QLineEdit::Normal,"",&ok);
           if(!addMedMsg.isEmpty())
           {
               if(listAvaliableMeds().contains(addMedMsg))
               {
                   QMessageBox::information(this,"Cannot Add","The medincine inputted cannot be inputeed, it already exist");
                   ui->medComboBox->setCurrentIndex(0);
               }
               else
               {
                   addMeds(addMedMsg);
                   ui->medComboBox->addItems(listAvaliableMeds());
                   ui->medComboBox->setCurrentText(addMedMsg);
               }
           }
           else
           {
               QMessageBox::information(this,"Empty","Nothing has been filled in boss");
               ui->medComboBox->setCurrentIndex(0);
           }

        }
        else
            qDebug()<<"nahh this aint the good stuff";
}


void EditPatient::on_patientComboBox_textActivated(const QString &arg1)
{
    QString currentSelection = ui->patientComboBox->currentText().split(" ").at(0);
    if(arg1 == "Select a patient")
    {
        ui->updateButton->setEnabled(false);
        //blank out all the inputs
        ui->firstNameEdit->setText("");
        ui->lastNameEdit->setText("");
        ui->ageInput->setText("");
        ui->phoneNumberEdit->setText("");
        ui->genderComboBox->setCurrentText("");
        ui->dobEdit->setDate(QDate::currentDate());
        ui->socialSecurityNumberInput->setText("");
        ui->doctorComboBox->setCurrentIndex(-1);
        //disable all the buttons
        ui->firstNameEdit->setEnabled(false);
        ui->lastNameEdit->setEnabled(false);
        ui->ageInput->setEnabled(false);
        ui->phoneNumberEdit->setEnabled(false);
        ui->genderComboBox->setEnabled(false);
        ui->dobEdit->setEnabled(false);
        ui->socialSecurityNumberInput->setEnabled(false);
        ui->doctorComboBox->setEnabled(false);
        ui->updateButton->setEnabled(false);
        //disabling the add schedling buttons
        ui->assignedNurseComboBox->setCurrentIndex(-1);
        ui->assignedNurseComboBox->setEnabled(false);
        ui->medComboBox->setCurrentIndex(-1);
        ui->medComboBox->setEnabled(false);
        ui->dosageValueInNum->setEnabled(false);
        ui->dosageValueInUnits->setEnabled(false);
        ui->intervaValueNum->setEnabled(false);
        ui->intervalValueComboBox->setCurrentIndex(-1);
        ui->intervalValueComboBox->setEnabled(false);
        ui->dateBeginLabel_2->setEnabled(false);
        ui->dateEndInput->setEnabled(false);
        ui->addToSchedule->setEnabled(false);
        ui->removeFromSchedule->setEnabled(false);
    }
    else
    {
        ui->firstNameEdit->setEnabled(true);
        ui->lastNameEdit->setEnabled(true);
        ui->ageInput->setEnabled(true);
        ui->phoneNumberEdit->setEnabled(true);
        ui->genderComboBox->setEnabled(true);
        ui->dobEdit->setEnabled(true);
        ui->socialSecurityNumberInput->setEnabled(true);
        ui->doctorComboBox->setEnabled(true);
        ui->updateButton->setEnabled(true);
        QStringList data = selectedPatientInfo(currentSelection);
        QDate dob= QDate::fromString(data[5],"yyyy-MM-dd");
        qDebug()<<"DOB output "<<dob;
        ui->firstNameEdit->setText(data[0]);
        ui->lastNameEdit->setText(data[1]);
        ui->ageInput->setText(data[2]);
        ui->phoneNumberEdit->setText(data[3]);
        ui->genderComboBox->setCurrentText(data[4]);
        ui->dobEdit->setDate(dob);
        ui->socialSecurityNumberInput->setText(data[6]);
        ui->updateButton->setEnabled(true);
        ui->doctorComboBox->setCurrentText(data[7]);
    }
}

