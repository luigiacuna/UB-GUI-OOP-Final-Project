#ifndef ADDEDITPATIENT_H
#define ADDEDITPATIENT_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class AddEditPatient;
}

class AddEditPatient : public QDialog, public Database
{
    Q_OBJECT

public:
    explicit AddEditPatient(int senario,QString,QWidget *parent = nullptr);
    ~AddEditPatient();
private slots:
    void openSenarioTwo();


    void on_medicineComboBox_textActivated(const QString &arg1);

private:
    Ui::AddEditPatient *ui;
    QString doctoruser;
};

#endif // ADDEDITPATIENT_H
