#ifndef NURSEVIEW_H
#define NURSEVIEW_H

#include <QMainWindow>
#include <QChart>
#include <QValueAxis>
#include <QTime>
#include <QDateTimeAxis>
#include <QLineSeries>
#include <QChart>
//#include <QScatterSeries>







namespace Ui {
class NurseView;
}

class NurseView : public QMainWindow
{
    Q_OBJECT

public:
    explicit NurseView(QWidget *parent = nullptr);
    ~NurseView();

private:
    Ui::NurseView *ui;
};

#endif // NURSEVIEW_H
