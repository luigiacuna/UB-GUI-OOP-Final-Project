#include "addeditpatient.h"
#include "ui_addeditpatient.h"

AddEditPatient::AddEditPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditPatient)
{
    ui->setupUi(this);
}

AddEditPatient::~AddEditPatient()
{
    delete ui;
}
