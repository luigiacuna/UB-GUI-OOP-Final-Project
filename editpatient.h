#ifndef EDITPATIENT_H
#define EDITPATIENT_H

#include <QDialog>
#include "database.h"

namespace Ui {
class EditPatient;
}

class EditPatient : public QDialog, public Database
{
    Q_OBJECT

public:
    explicit EditPatient(QString patient, QWidget *parent = nullptr);
    ~EditPatient();

private:
    Ui::EditPatient *ui;
};

#endif // EDITPATIENT_H
