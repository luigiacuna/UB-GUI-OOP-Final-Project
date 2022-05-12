#ifndef EDITPATIENT_H
#define EDITPATIENT_H

#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
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

private slots:
    void updateButtonPressed();
    void addButtonPressed();
    void removeFromSchedulePressed();
    void on_medComboBox_textActivated(const QString &arg1);

    void on_patientComboBox_textActivated(const QString &arg1);


    void on_idScheduleView_activated(const QModelIndex &index);

private:
    Ui::EditPatient *ui;
    QString sID;
};

#endif // EDITPATIENT_H
