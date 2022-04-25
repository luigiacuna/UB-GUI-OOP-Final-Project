#ifndef ADDEDITPATIENT_H
#define ADDEDITPATIENT_H

#include <QDialog>

namespace Ui {
class AddEditPatient;
}

class AddEditPatient : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditPatient(int senario,QWidget *parent = nullptr);
    ~AddEditPatient();

private:
    Ui::AddEditPatient *ui;
};

#endif // ADDEDITPATIENT_H
