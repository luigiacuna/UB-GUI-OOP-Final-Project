#include "doctorview.h"
#include "ui_doctorview.h"

DoctorView::DoctorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);
    QPixmap pix("C:/heheboi.jpg");
    ui->companyLogo->setPixmap(pix);
    connect(ui->addPatient,SIGNAL(clicked()),this,SLOT(createNewPatient()));
    connect(ui->viewPatient,SIGNAL(clicked()),this,SLOT(editPatient()));

}

DoctorView::~DoctorView()
{
    delete ui;
}

void DoctorView::createNewPatient()
{
    AddEditPatient openSen1(1);
    openSen1.setModal(true);
    openSen1.exec();
}

void DoctorView::editPatient()
{
    AddEditPatient openSen1(2);
    openSen1.setModal(true);
    openSen1.exec();
}
