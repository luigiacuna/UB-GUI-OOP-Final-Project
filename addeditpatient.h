#ifndef ADDEDITPATIENT_H
#define ADDEDITPATIENT_H

#include <QDialog>
#include "database.h"
#include "doctorview.h"

namespace Ui {
class AddEditPatient;
}

class AddEditPatient : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditPatient(QString doctor,QWidget *parent = nullptr);
    ~AddEditPatient();

private slots:

    void createButtonPressed();

    void on_cancelButton_clicked();

private:
    Ui::AddEditPatient *ui;
    Database db;
    QString doctorUsername;

};

#endif // ADDEDITPATIENT_H
