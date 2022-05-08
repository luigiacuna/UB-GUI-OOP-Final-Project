#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QMainWindow>
#include <QPixmap>
#include "addeditpatient.h"
#include "addmedicine.h"
#include "database.h"

namespace Ui {
class DoctorView;
}

class DoctorView : public QMainWindow,public Database
{
    Q_OBJECT

public:
    explicit DoctorView(QString,QString,QWidget *parent = nullptr);
    ~DoctorView();
private slots:
    void createNewPatient();
    void editPatient();
    void addMedicine();

private:
    Ui::DoctorView *ui;
    QString doctorUsername;
};

#endif // DOCTORVIEW_H
