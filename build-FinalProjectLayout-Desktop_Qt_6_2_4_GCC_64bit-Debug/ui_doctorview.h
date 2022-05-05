/********************************************************************************
** Form generated from reading UI file 'doctorview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORVIEW_H
#define UI_DOCTORVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorView
{
public:
    QAction *actionAbout;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *crissCross;
    QVBoxLayout *slideToTheLeft;
    QPushButton *addPatient;
    QPushButton *viewPatient;
    QSpacerItem *horizontalSpacer;
    QLabel *companyLogo;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *slideToTheRight;
    QPushButton *seeSchedule;
    QPushButton *reportsButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoctorView)
    {
        if (DoctorView->objectName().isEmpty())
            DoctorView->setObjectName(QString::fromUtf8("DoctorView"));
        DoctorView->resize(800, 600);
        actionAbout = new QAction(DoctorView);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(DoctorView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 40, 721, 471));
        crissCross = new QHBoxLayout(layoutWidget);
        crissCross->setObjectName(QString::fromUtf8("crissCross"));
        crissCross->setContentsMargins(0, 0, 0, 0);
        slideToTheLeft = new QVBoxLayout();
        slideToTheLeft->setObjectName(QString::fromUtf8("slideToTheLeft"));
        addPatient = new QPushButton(layoutWidget);
        addPatient->setObjectName(QString::fromUtf8("addPatient"));

        slideToTheLeft->addWidget(addPatient);

        viewPatient = new QPushButton(layoutWidget);
        viewPatient->setObjectName(QString::fromUtf8("viewPatient"));

        slideToTheLeft->addWidget(viewPatient);


        crissCross->addLayout(slideToTheLeft);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        crissCross->addItem(horizontalSpacer);

        companyLogo = new QLabel(layoutWidget);
        companyLogo->setObjectName(QString::fromUtf8("companyLogo"));
        companyLogo->setAlignment(Qt::AlignCenter);

        crissCross->addWidget(companyLogo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        crissCross->addItem(horizontalSpacer_2);

        slideToTheRight = new QVBoxLayout();
        slideToTheRight->setObjectName(QString::fromUtf8("slideToTheRight"));
        seeSchedule = new QPushButton(layoutWidget);
        seeSchedule->setObjectName(QString::fromUtf8("seeSchedule"));

        slideToTheRight->addWidget(seeSchedule);

        reportsButton = new QPushButton(layoutWidget);
        reportsButton->setObjectName(QString::fromUtf8("reportsButton"));

        slideToTheRight->addWidget(reportsButton);


        crissCross->addLayout(slideToTheRight);

        DoctorView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoctorView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        DoctorView->setMenuBar(menubar);
        statusbar = new QStatusBar(DoctorView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DoctorView->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);

        retranslateUi(DoctorView);

        QMetaObject::connectSlotsByName(DoctorView);
    } // setupUi

    void retranslateUi(QMainWindow *DoctorView)
    {
        DoctorView->setWindowTitle(QCoreApplication::translate("DoctorView", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("DoctorView", "About", nullptr));
        addPatient->setText(QCoreApplication::translate("DoctorView", "Add Patient", nullptr));
        viewPatient->setText(QCoreApplication::translate("DoctorView", "View Patient", nullptr));
        companyLogo->setText(QCoreApplication::translate("DoctorView", "Company Logo", nullptr));
        seeSchedule->setText(QCoreApplication::translate("DoctorView", "Nurse Scedule", nullptr));
        reportsButton->setText(QCoreApplication::translate("DoctorView", "Reports", nullptr));
        menuFile->setTitle(QCoreApplication::translate("DoctorView", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("DoctorView", "Herpes Me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorView: public Ui_DoctorView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORVIEW_H
