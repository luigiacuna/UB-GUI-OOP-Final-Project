#include "doctorview.h"
#include "ui_doctorview.h"

DoctorView::DoctorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);
    QPixmap pix("C:/heheboi.jpg");
    ui->companyLogo->setPixmap(pix);

}

DoctorView::~DoctorView()
{
    delete ui;
}
