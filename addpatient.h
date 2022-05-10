#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>
#include "database.h"
#include "editpatient.h"

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

private:
    Ui::AddPatient *ui;
    QString doctorUsername;
};

#endif // ADDPATIENT_H
