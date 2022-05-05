/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_Login
{
public:
    QLabel *tempLabel;
    QWidget *layoutWidget;
    QVBoxLayout *LoginLayoutBox;
    QHBoxLayout *userNameLayoutBox;
    QLabel *userNameLabel;
    QLineEdit *userNameInput;
    QHBoxLayout *passwordLayoutBox;
    QLabel *passwordLabel;
    QLineEdit *passwordInput;
    QPushButton *onOkButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *newUser;
    QLabel *userNameError;
    QLabel *incorrectAnything;
    QLabel *passwordError;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(917, 600);
        tempLabel = new QLabel(Login);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        tempLabel->setGeometry(QRect(380, 120, 151, 31));
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 190, 571, 261));
        LoginLayoutBox = new QVBoxLayout(layoutWidget);
        LoginLayoutBox->setObjectName(QString::fromUtf8("LoginLayoutBox"));
        LoginLayoutBox->setContentsMargins(0, 0, 0, 0);
        userNameLayoutBox = new QHBoxLayout();
        userNameLayoutBox->setObjectName(QString::fromUtf8("userNameLayoutBox"));
        userNameLabel = new QLabel(layoutWidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        userNameLayoutBox->addWidget(userNameLabel);

        userNameInput = new QLineEdit(layoutWidget);
        userNameInput->setObjectName(QString::fromUtf8("userNameInput"));
        userNameInput->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        userNameLayoutBox->addWidget(userNameInput);


        LoginLayoutBox->addLayout(userNameLayoutBox);

        passwordLayoutBox = new QHBoxLayout();
        passwordLayoutBox->setObjectName(QString::fromUtf8("passwordLayoutBox"));
        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        passwordLayoutBox->addWidget(passwordLabel);

        passwordInput = new QLineEdit(layoutWidget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        passwordLayoutBox->addWidget(passwordInput);


        LoginLayoutBox->addLayout(passwordLayoutBox);

        onOkButton = new QPushButton(layoutWidget);
        onOkButton->setObjectName(QString::fromUtf8("onOkButton"));

        LoginLayoutBox->addWidget(onOkButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newUser = new QPushButton(layoutWidget);
        newUser->setObjectName(QString::fromUtf8("newUser"));

        horizontalLayout->addWidget(newUser);


        LoginLayoutBox->addLayout(horizontalLayout);

        userNameError = new QLabel(Login);
        userNameError->setObjectName(QString::fromUtf8("userNameError"));
        userNameError->setGeometry(QRect(760, 220, 141, 20));
        incorrectAnything = new QLabel(Login);
        incorrectAnything->setObjectName(QString::fromUtf8("incorrectAnything"));
        incorrectAnything->setGeometry(QRect(200, 160, 491, 20));
        incorrectAnything->setAlignment(Qt::AlignCenter);
        passwordError = new QLabel(Login);
        passwordError->setObjectName(QString::fromUtf8("passwordError"));
        passwordError->setGeometry(QRect(760, 290, 51, 21));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        tempLabel->setText(QCoreApplication::translate("Login", "Final Project Login Layout", nullptr));
        userNameLabel->setText(QCoreApplication::translate("Login", "Username: ", nullptr));
        userNameInput->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("Login", "Password: ", nullptr));
        passwordInput->setText(QString());
        onOkButton->setText(QCoreApplication::translate("Login", "OK", nullptr));
        newUser->setText(QCoreApplication::translate("Login", "New User", nullptr));
        userNameError->setText(QString());
        incorrectAnything->setText(QString());
        passwordError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
