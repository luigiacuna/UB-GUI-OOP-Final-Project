#include "nurseview.h"
#include "ui_nurseview.h"

NurseView::NurseView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NurseView)
{
    ui->setupUi(this);
        //Testing example
        /*QBarSet * set0 = new QBarSet("Jane");
        QBarSet * set1 = new QBarSet("John");
        QBarSet * set2 = new QBarSet("Axel");
        QBarSet * set3 = new QBarSet("Mary");
        QBarSet * set4 = new QBarSet("Samanta");

        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple Barchart Example");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,15);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);*/

//////////////////////////////////////////////////////////////////////////
///
///
    //trying with a bar chart to see if this can be achevied

    //the patients will be on the y axis and the current time will be on the x axis
//        QLineSeries *series = new QLineSeries;
//        series->append(2023,2);

//        QChart *chart= new QChart();
//        chart->addSeries(series);
//        chart->legend()->hide();
//        chart->setTitle("Nurse's Scedule");

//        QDateTimeAxis *axisX = new QDateTimeAxis;
//        axisX->setTickCount(10);
//        axisX->setFormat("MMM yyyy");
//        axisX->setTitleText("Date");
//        chart->addAxis(axisX,Qt::AlignBottom);
//        series->attachAxis(axisX);
        //ui->graphicsView->chart()->addAxis(axisX,Qt::AlignBottom);
        //ui->graphicsView->setChart(chart);





        /*QValueAxis *axisX= new QValueAxis;
        axisX->setRange(10,20);
        axisX->setTickCount(10);
        axisX->setLabelFormat("%.0f");*/


       //ui->graphicsView->chart()->addAxis(axisX,Qt::AlignBottom);
       //ui->graphicsView->chart()->setAxisX(axisX,series);
        //ui->graphicsView->setChart(chart);
ui->schedule->verticalHeader()->setVisible(false);
ui->schedule->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//fit all the contents of the sql query to fit on the table width
ui->schedule->setSelectionBehavior(QAbstractItemView::SelectItems);//allows only one item to be selected at a time
ui->schedule->setSelectionMode(QAbstractItemView::SingleSelection);//whatever was selected becomes deselectd and the new item clicked becomes seleceted
ui->schedule->setModel(db.scheduleTable());

}

NurseView::~NurseView()
{
    delete ui;
}
