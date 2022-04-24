#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QMainWindow>
#include <QPixmap>

namespace Ui {
class DoctorView;
}

class DoctorView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorView(QWidget *parent = nullptr);
    ~DoctorView();

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
