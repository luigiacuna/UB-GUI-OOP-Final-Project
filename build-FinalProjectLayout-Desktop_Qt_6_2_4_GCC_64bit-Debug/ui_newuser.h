/********************************************************************************
** Form generated from reading UI file 'newuser.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSER_H
#define UI_NEWUSER_H

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

class Ui_NewUser
{
public:
    QLabel *title;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *Labels;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *userNameLabel;
    QLabel *passwordLabel;
    QLabel *reneterPasswordLabel;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *firstName;
    QLineEdit *firstNameInput;
    QHBoxLayout *lastName;
    QLineEdit *lastNameInput;
    QHBoxLayout *userName;
    QLineEdit *userNameInput;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *passwordInput;
    QHBoxLayout *renterPassword;
    QLineEdit *renterPasswordInput;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *firstNameRequired;
    QLabel *lastNameRequired;
    QLabel *passwordRequired;
    QLabel *userNameRequired;
    QLabel *renterPasswordRequired;

    void setupUi(QDialog *NewUser)
    {
        if (NewUser->objectName().isEmpty())
            NewUser->setObjectName(QString::fromUtf8("NewUser"));
        NewUser->resize(899, 520);
        title = new QLabel(NewUser);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(300, 50, 101, 16));
        layoutWidget = new QWidget(NewUser);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(36, 91, 621, 341));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Labels = new QVBoxLayout();
        Labels->setObjectName(QString::fromUtf8("Labels"));
        firstNameLabel = new QLabel(layoutWidget);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));

        Labels->addWidget(firstNameLabel);

        lastNameLabel = new QLabel(layoutWidget);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));

        Labels->addWidget(lastNameLabel);

        userNameLabel = new QLabel(layoutWidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        Labels->addWidget(userNameLabel);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        Labels->addWidget(passwordLabel);

        reneterPasswordLabel = new QLabel(layoutWidget);
        reneterPasswordLabel->setObjectName(QString::fromUtf8("reneterPasswordLabel"));

        Labels->addWidget(reneterPasswordLabel);


        horizontalLayout_3->addLayout(Labels);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        firstName = new QHBoxLayout();
        firstName->setObjectName(QString::fromUtf8("firstName"));
        firstNameInput = new QLineEdit(layoutWidget);
        firstNameInput->setObjectName(QString::fromUtf8("firstNameInput"));

        firstName->addWidget(firstNameInput);


        verticalLayout->addLayout(firstName);

        lastName = new QHBoxLayout();
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastNameInput = new QLineEdit(layoutWidget);
        lastNameInput->setObjectName(QString::fromUtf8("lastNameInput"));

        lastName->addWidget(lastNameInput);


        verticalLayout->addLayout(lastName);

        userName = new QHBoxLayout();
        userName->setObjectName(QString::fromUtf8("userName"));
        userNameInput = new QLineEdit(layoutWidget);
        userNameInput->setObjectName(QString::fromUtf8("userNameInput"));

        userName->addWidget(userNameInput);


        verticalLayout->addLayout(userName);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        passwordInput = new QLineEdit(layoutWidget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));

        horizontalLayout_4->addWidget(passwordInput);


        verticalLayout->addLayout(horizontalLayout_4);

        renterPassword = new QHBoxLayout();
        renterPassword->setObjectName(QString::fromUtf8("renterPassword"));
        renterPasswordInput = new QLineEdit(layoutWidget);
        renterPasswordInput->setObjectName(QString::fromUtf8("renterPasswordInput"));

        renterPassword->addWidget(renterPasswordInput);


        verticalLayout->addLayout(renterPassword);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        okButton = new QPushButton(NewUser);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(230, 460, 80, 24));
        cancelButton = new QPushButton(NewUser);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(380, 460, 80, 24));
        firstNameRequired = new QLabel(NewUser);
        firstNameRequired->setObjectName(QString::fromUtf8("firstNameRequired"));
        firstNameRequired->setGeometry(QRect(690, 110, 151, 31));
        lastNameRequired = new QLabel(NewUser);
        lastNameRequired->setObjectName(QString::fromUtf8("lastNameRequired"));
        lastNameRequired->setGeometry(QRect(690, 180, 121, 31));
        passwordRequired = new QLabel(NewUser);
        passwordRequired->setObjectName(QString::fromUtf8("passwordRequired"));
        passwordRequired->setGeometry(QRect(710, 310, 126, 31));
        userNameRequired = new QLabel(NewUser);
        userNameRequired->setObjectName(QString::fromUtf8("userNameRequired"));
        userNameRequired->setGeometry(QRect(690, 240, 171, 31));
        renterPasswordRequired = new QLabel(NewUser);
        renterPasswordRequired->setObjectName(QString::fromUtf8("renterPasswordRequired"));
        renterPasswordRequired->setGeometry(QRect(700, 380, 211, 41));

        retranslateUi(NewUser);

        QMetaObject::connectSlotsByName(NewUser);
    } // setupUi

    void retranslateUi(QDialog *NewUser)
    {
        NewUser->setWindowTitle(QCoreApplication::translate("NewUser", "Dialog", nullptr));
        title->setText(QCoreApplication::translate("NewUser", "Create a new User", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("NewUser", "First Name:", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("NewUser", "Last Name: ", nullptr));
        userNameLabel->setText(QCoreApplication::translate("NewUser", "Username: ", nullptr));
        passwordLabel->setText(QCoreApplication::translate("NewUser", "Password: ", nullptr));
        reneterPasswordLabel->setText(QCoreApplication::translate("NewUser", "Renter Password", nullptr));
        okButton->setText(QCoreApplication::translate("NewUser", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("NewUser", "Cancel", nullptr));
        firstNameRequired->setText(QCoreApplication::translate("NewUser", "Required", nullptr));
        lastNameRequired->setText(QCoreApplication::translate("NewUser", "Required", nullptr));
        passwordRequired->setText(QCoreApplication::translate("NewUser", "Required", nullptr));
        userNameRequired->setText(QCoreApplication::translate("NewUser", "Username already taken", nullptr));
        renterPasswordRequired->setText(QCoreApplication::translate("NewUser", "Please reneter password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewUser: public Ui_NewUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSER_H
