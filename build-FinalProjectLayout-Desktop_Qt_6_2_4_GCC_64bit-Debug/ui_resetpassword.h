/********************************************************************************
** Form generated from reading UI file 'resetpassword.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORD_H
#define UI_RESETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResetPassword
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *newPasswordLayout;
    QLabel *newPassword;
    QLineEdit *newPasswordInput;
    QHBoxLayout *renterPasswordLayout;
    QLabel *renterPasswordLabel;
    QLineEdit *renterPasswordInput;
    QHBoxLayout *buttons;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *ResetPassword)
    {
        if (ResetPassword->objectName().isEmpty())
            ResetPassword->setObjectName(QString::fromUtf8("ResetPassword"));
        ResetPassword->resize(400, 300);
        layoutWidget = new QWidget(ResetPassword);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 331, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newPasswordLayout = new QHBoxLayout();
        newPasswordLayout->setObjectName(QString::fromUtf8("newPasswordLayout"));
        newPassword = new QLabel(layoutWidget);
        newPassword->setObjectName(QString::fromUtf8("newPassword"));

        newPasswordLayout->addWidget(newPassword);

        newPasswordInput = new QLineEdit(layoutWidget);
        newPasswordInput->setObjectName(QString::fromUtf8("newPasswordInput"));

        newPasswordLayout->addWidget(newPasswordInput);


        verticalLayout->addLayout(newPasswordLayout);

        renterPasswordLayout = new QHBoxLayout();
        renterPasswordLayout->setObjectName(QString::fromUtf8("renterPasswordLayout"));
        renterPasswordLabel = new QLabel(layoutWidget);
        renterPasswordLabel->setObjectName(QString::fromUtf8("renterPasswordLabel"));

        renterPasswordLayout->addWidget(renterPasswordLabel);

        renterPasswordInput = new QLineEdit(layoutWidget);
        renterPasswordInput->setObjectName(QString::fromUtf8("renterPasswordInput"));

        renterPasswordLayout->addWidget(renterPasswordInput);


        verticalLayout->addLayout(renterPasswordLayout);

        buttons = new QHBoxLayout();
        buttons->setObjectName(QString::fromUtf8("buttons"));
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        buttons->addWidget(cancelButton);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        buttons->addWidget(okButton);


        verticalLayout->addLayout(buttons);


        retranslateUi(ResetPassword);

        QMetaObject::connectSlotsByName(ResetPassword);
    } // setupUi

    void retranslateUi(QDialog *ResetPassword)
    {
        ResetPassword->setWindowTitle(QCoreApplication::translate("ResetPassword", "Dialog", nullptr));
        newPassword->setText(QCoreApplication::translate("ResetPassword", "New Password:   ", nullptr));
        renterPasswordLabel->setText(QCoreApplication::translate("ResetPassword", "Renter Password:", nullptr));
        cancelButton->setText(QCoreApplication::translate("ResetPassword", "Cancel", nullptr));
        okButton->setText(QCoreApplication::translate("ResetPassword", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetPassword: public Ui_ResetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORD_H
