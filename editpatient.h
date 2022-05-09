#ifndef EDITPATIENT_H
#define EDITPATIENT_H

#include <QDialog>

namespace Ui {
class EditPatient;
}

class EditPatient : public QDialog
{
    Q_OBJECT

public:
    explicit EditPatient(QString patient, QWidget *parent = nullptr);
    ~EditPatient();

private:
    Ui::EditPatient *ui;
};

#endif // EDITPATIENT_H
