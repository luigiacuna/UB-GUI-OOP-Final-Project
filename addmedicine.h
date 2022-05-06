#ifndef ADDMEDICINE_H
#define ADDMEDICINE_H

#include <QDialog>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class AddMedicine;
}

class AddMedicine : public QDialog, public Database
{
    Q_OBJECT

public:
    explicit AddMedicine(QWidget *parent = nullptr);
    ~AddMedicine();
private slots:
    void okButtonPressed();
    void removeButtonPressed();
    void cancelButtonPressed();

    void on_avaliableMedsView_activated(const QModelIndex &index);

private:
    Ui::AddMedicine *ui;
    QString medSelected;
};

#endif // ADDMEDICINE_H
