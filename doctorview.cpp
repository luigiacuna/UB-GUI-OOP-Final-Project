#include "doctorview.h"
#include "ui_doctorview.h"

DoctorView::DoctorView(QString username, QString role, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);
    doctorUsername = username;
    QPixmap pix("C:/heheboi.jpg");
    ui->companyLogo->setPixmap(pix);
    connect(ui->addPatient,SIGNAL(clicked()),this,SLOT(createNewPatient()));
    connect(ui->viewPatient,SIGNAL(clicked()),this,SLOT(editPatient()));
    connect(ui->addMeds,SIGNAL(clicked()),this,SLOT(addMedicine()));

    ui->statusbar->showMessage("Logged in as: Dr. "+getFullName(username,role));

}

DoctorView::~DoctorView()
{
    delete ui;
}

void DoctorView::createNewPatient()
{
    AddEditPatient openSen1(1,doctorUsername);
    openSen1.setModal(true);
    openSen1.exec();
}

void DoctorView::editPatient()
{
    AddEditPatient openSen1(2,doctorUsername);
    openSen1.setModal(true);
    openSen1.exec();
}

void DoctorView::addMedicine()
{
    AddMedicine meds;
    meds.setModal(true);
    meds.exec();
}
