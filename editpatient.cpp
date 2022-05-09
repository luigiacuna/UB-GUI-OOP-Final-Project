#include "editpatient.h"
#include "ui_editpatient.h"

EditPatient::EditPatient(QString patient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPatient)
{
    ui->setupUi(this);
}

EditPatient::~EditPatient()
{
    delete ui;
}
