/********************************************************************************
** Form generated from reading UI file 'nurseview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NURSEVIEW_H
#define UI_NURSEVIEW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NurseView
{
public:
    QAction *actionAbout;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QChartView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NurseView)
    {
        if (NurseView->objectName().isEmpty())
            NurseView->setObjectName(QString::fromUtf8("NurseView"));
        NurseView->resize(800, 600);
        actionAbout = new QAction(NurseView);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(NurseView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 520, 80, 24));
        graphicsView = new QChartView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 30, 761, 461));
        NurseView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NurseView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        NurseView->setMenuBar(menubar);
        statusbar = new QStatusBar(NurseView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NurseView->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);

        retranslateUi(NurseView);

        QMetaObject::connectSlotsByName(NurseView);
    } // setupUi

    void retranslateUi(QMainWindow *NurseView)
    {
        NurseView->setWindowTitle(QCoreApplication::translate("NurseView", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("NurseView", "About", nullptr));
        pushButton->setText(QCoreApplication::translate("NurseView", "PushButton", nullptr));
        menuFile->setTitle(QCoreApplication::translate("NurseView", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("NurseView", "Herpes Me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NurseView: public Ui_NurseView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NURSEVIEW_H
