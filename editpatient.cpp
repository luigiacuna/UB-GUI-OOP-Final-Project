#include "editpatient.h"
#include "ui_editpatient.h"

EditPatient::EditPatient(QString patient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPatient)
{
    ui->setupUi(this);
    //pushing items that are already established in the database
    ui->assignedNurseComboBox->addItems(listAvaliableNurses());
    ui->medComboBox->addItems(listAvaliableMeds());
    //filling the patient combo box with the avaliable patients that have been created
    ui->patientComboBox->addItem("Select a patient");
    ui->patientComboBox->addItems(listAvaliablePatients());//to be grabbed from the patient data portion need to create db function
    if(patient == "")
    {
        ui->patientComboBox->setCurrentIndex(0);
        ui->updateButton->setEnabled(false);
    }
}

EditPatient::~EditPatient()
{
    delete ui;
}
