#include "addeditpatient.h"
#include "ui_addeditpatient.h"

AddEditPatient::AddEditPatient(int senario,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditPatient)
{
    ui->setupUi(this);
    if(senario == 1)
    {
        //This will imply that the doctor wants to create a new patient
         ui->selectedPatientLabel->hide();
         ui->selectedPatientCombo->hide();
         //do fancy stuff
    }
    else if(senario == 2)

    {
        //This implies that the doctor wants to edit an existing patient
        //This will change the ok button to say update
        //a combo box will be viewable allowing the doctor to pick which patient to edit
        ui->okButton->setText("Update");
        //do fancy stuff
    }
}

AddEditPatient::~AddEditPatient()
{
    delete ui;
}
