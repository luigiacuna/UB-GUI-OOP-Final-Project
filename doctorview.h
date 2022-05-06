#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QMainWindow>
#include <QPixmap>
#include "addeditpatient.h"
#include "addmedicine.h"

namespace Ui {
class DoctorView;
}

class DoctorView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorView(QWidget *parent = nullptr);
    ~DoctorView();
private slots:
    void createNewPatient();
    void editPatient();
    void addMedicine();

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
