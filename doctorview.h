#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QMainWindow>
#include <QPixmap>
#include "addpatient.h"
#include "Login.h"
#include "addmedicine.h"
#include "editpatient.h"
#include "database.h"

#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <QValueAxis>


namespace Ui {
class DoctorView;
}

class DoctorView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorView(QString username, QString role, QWidget *parent = nullptr);
    ~DoctorView();
private slots:
    void createNewPatient();
    void editPatient();
    void addMedicine();

    void on_Logout_clicked();

    void on_reportsButton_clicked();

private:
    Ui::DoctorView *ui;
    Database db;
    QString doctorUsername;
};

#endif // DOCTORVIEW_H
