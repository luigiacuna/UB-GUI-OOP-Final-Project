#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>
#include "database.h"
#include "editpatient.h"
#include "QFile"

namespace Ui {
class AddPatient;
}

class AddPatient : public QDialog, public Database
{
    Q_OBJECT

public:
    explicit AddPatient(QString, QWidget *parent = nullptr);
    ~AddPatient();

private slots:
    void createButtonPressed();

    void on_firstNameInput_editingFinished();

    void on_lastNameInput_editingFinished();

    void on_ageInput_editingFinished();

    void on_phoneNumberInput_editingFinished();

    void on_genderComboBox_textActivated(const QString &arg1);

    void on_dateEdit_editingFinished();


    void on_ssNumInput_editingFinished();



private:
    Ui::AddPatient *ui;
    QString doctorUsername;
};

#endif // ADDPATIENT_H
