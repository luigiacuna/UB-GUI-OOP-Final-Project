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

void DoctorView::on_reportsButton_clicked()
{
    /*QBarSet * set0 = new QBarSet(db.medChart());
    QBarSet * set1 = new QBarSet(db.medChart());
    QBarSet * set2 = new QBarSet(db.medChart());
    QBarSet * set3 = new QBarSet(db.medChart());
    QBarSet * set4 = new QBarSet(db.medChart());*/
    QBarSet * set0 = new QBarSet("Medicine frequently used by patients");
    QList<int> values=db.medChart();
    qDebug()<<"Values figures: "<<values;
   for(int count =0;count<values.size();count++)
   {
       qDebug()<<values[count];
       *set0<<values[count];
   }

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    /*series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);*/

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Medicine Report");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(db.medCategory());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,15);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *window = new QMainWindow(this);
    window->setCentralWidget(chartView);
    window->resize(420, 300);
    window->show();
}
