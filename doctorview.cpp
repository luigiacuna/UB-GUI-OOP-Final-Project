#include "doctorview.h"
#include "ui_doctorview.h"

DoctorView::DoctorView(QString username, QString role, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);
    QPixmap pix("C:/heheboi.jpg");
    ui->companyLogo->setPixmap(pix);
    connect(ui->addPatient,SIGNAL(clicked()),this,SLOT(createNewPatient()));
    connect(ui->viewPatient,SIGNAL(clicked()),this,SLOT(editPatient()));
    connect(ui->addMeds,SIGNAL(clicked()),this,SLOT(addMedicine()));

    ui->statusbar->showMessage("Logged in as: Dr. "+db.getFullName(username,role));
    doctorUsername = username;


}

DoctorView::~DoctorView()
{
    delete ui;
}

void DoctorView::createNewPatient()
{
    AddPatient addPat(doctorUsername);
    addPat.setModal(true);
    addPat.exec();
}

void DoctorView::editPatient()
{
    EditPatient editPat("");
    editPat.setModal(true);
    editPat.exec();
}

void DoctorView::addMedicine()
{
    AddMedicine meds;
    meds.setModal(true);
    meds.exec();
}


void DoctorView::on_Logout_clicked()
{
    Login login;
    this->close();
    login.exec();
}
