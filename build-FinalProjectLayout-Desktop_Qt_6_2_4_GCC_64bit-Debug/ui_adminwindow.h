/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralwidget;
    QLabel *currrenTimeLabel;
    QLabel *actualTimeLabel;
    QLabel *adminLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *editUser;
    QPushButton *createUserButton;
    QPushButton *resetUserPasswordButton;
    QPushButton *DeleteUser;
    QTableView *usernameView;
    QTableView *everythingElse;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(542, 600);
        actionAbout = new QAction(AdminWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(AdminWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        currrenTimeLabel = new QLabel(centralwidget);
        currrenTimeLabel->setObjectName(QString::fromUtf8("currrenTimeLabel"));
        currrenTimeLabel->setGeometry(QRect(300, 540, 101, 16));
        actualTimeLabel = new QLabel(centralwidget);
        actualTimeLabel->setObjectName(QString::fromUtf8("actualTimeLabel"));
        actualTimeLabel->setGeometry(QRect(440, 540, 151, 20));
        adminLabel = new QLabel(centralwidget);
        adminLabel->setObjectName(QString::fromUtf8("adminLabel"));
        adminLabel->setGeometry(QRect(20, 10, 501, 20));
        adminLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 510, 521, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        editUser = new QPushButton(layoutWidget);
        editUser->setObjectName(QString::fromUtf8("editUser"));

        horizontalLayout->addWidget(editUser);

        createUserButton = new QPushButton(layoutWidget);
        createUserButton->setObjectName(QString::fromUtf8("createUserButton"));

        horizontalLayout->addWidget(createUserButton);

        resetUserPasswordButton = new QPushButton(layoutWidget);
        resetUserPasswordButton->setObjectName(QString::fromUtf8("resetUserPasswordButton"));

        horizontalLayout->addWidget(resetUserPasswordButton);

        DeleteUser = new QPushButton(layoutWidget);
        DeleteUser->setObjectName(QString::fromUtf8("DeleteUser"));

        horizontalLayout->addWidget(DeleteUser);

        usernameView = new QTableView(centralwidget);
        usernameView->setObjectName(QString::fromUtf8("usernameView"));
        usernameView->setGeometry(QRect(13, 43, 121, 461));
        everythingElse = new QTableView(centralwidget);
        everythingElse->setObjectName(QString::fromUtf8("everythingElse"));
        everythingElse->setGeometry(QRect(130, 43, 401, 461));
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 542, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("AdminWindow", "About", nullptr));
        actionExit->setText(QCoreApplication::translate("AdminWindow", "Exit", nullptr));
        currrenTimeLabel->setText(QCoreApplication::translate("AdminWindow", "Current Time:", nullptr));
        actualTimeLabel->setText(QCoreApplication::translate("AdminWindow", "Time", nullptr));
        adminLabel->setText(QCoreApplication::translate("AdminWindow", "Administration Panel", nullptr));
        editUser->setText(QCoreApplication::translate("AdminWindow", "Edit User", nullptr));
        createUserButton->setText(QCoreApplication::translate("AdminWindow", "Create User", nullptr));
        resetUserPasswordButton->setText(QCoreApplication::translate("AdminWindow", "Reset User Password", nullptr));
        DeleteUser->setText(QCoreApplication::translate("AdminWindow", "Delete User", nullptr));
        menuFile->setTitle(QCoreApplication::translate("AdminWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("AdminWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
