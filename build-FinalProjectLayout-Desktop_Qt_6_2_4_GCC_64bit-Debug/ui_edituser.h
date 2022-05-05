/********************************************************************************
** Form generated from reading UI file 'edituser.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSER_H
#define UI_EDITUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditUser
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *buttonsLayout;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *editUserMainLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *labelsLayout;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *userNameLabel;
    QLabel *roleLabel;
    QVBoxLayout *inputsLayout;
    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *usernameInput;
    QComboBox *roleComboBox;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *firstNameEmptyLabel;
    QLabel *lastNameEmptyLabel;
    QLabel *usernameNotValidLabel;

    void setupUi(QDialog *EditUser)
    {
        if (EditUser->objectName().isEmpty())
            EditUser->setObjectName(QString::fromUtf8("EditUser"));
        EditUser->resize(448, 357);
        layoutWidget = new QWidget(EditUser);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 300, 331, 26));
        buttonsLayout = new QHBoxLayout(layoutWidget);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        buttonsLayout->addWidget(cancelButton);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        buttonsLayout->addWidget(okButton);

        layoutWidget1 = new QWidget(EditUser);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 53, 341, 231));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        editUserMainLabel = new QLabel(layoutWidget1);
        editUserMainLabel->setObjectName(QString::fromUtf8("editUserMainLabel"));
        editUserMainLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(editUserMainLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelsLayout = new QVBoxLayout();
        labelsLayout->setObjectName(QString::fromUtf8("labelsLayout"));
        firstNameLabel = new QLabel(layoutWidget1);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));

        labelsLayout->addWidget(firstNameLabel);

        lastNameLabel = new QLabel(layoutWidget1);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));

        labelsLayout->addWidget(lastNameLabel);

        userNameLabel = new QLabel(layoutWidget1);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        labelsLayout->addWidget(userNameLabel);

        roleLabel = new QLabel(layoutWidget1);
        roleLabel->setObjectName(QString::fromUtf8("roleLabel"));

        labelsLayout->addWidget(roleLabel);


        horizontalLayout->addLayout(labelsLayout);

        inputsLayout = new QVBoxLayout();
        inputsLayout->setObjectName(QString::fromUtf8("inputsLayout"));
        firstNameInput = new QLineEdit(layoutWidget1);
        firstNameInput->setObjectName(QString::fromUtf8("firstNameInput"));

        inputsLayout->addWidget(firstNameInput);

        lastNameInput = new QLineEdit(layoutWidget1);
        lastNameInput->setObjectName(QString::fromUtf8("lastNameInput"));

        inputsLayout->addWidget(lastNameInput);

        usernameInput = new QLineEdit(layoutWidget1);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));

        inputsLayout->addWidget(usernameInput);

        roleComboBox = new QComboBox(layoutWidget1);
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->setObjectName(QString::fromUtf8("roleComboBox"));
        roleComboBox->setLayoutDirection(Qt::LeftToRight);

        inputsLayout->addWidget(roleComboBox);


        horizontalLayout->addLayout(inputsLayout);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget2 = new QWidget(EditUser);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(370, 170, 71, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        firstNameEmptyLabel = new QLabel(layoutWidget2);
        firstNameEmptyLabel->setObjectName(QString::fromUtf8("firstNameEmptyLabel"));
        firstNameEmptyLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(firstNameEmptyLabel);

        lastNameEmptyLabel = new QLabel(layoutWidget2);
        lastNameEmptyLabel->setObjectName(QString::fromUtf8("lastNameEmptyLabel"));
        lastNameEmptyLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lastNameEmptyLabel);

        usernameNotValidLabel = new QLabel(layoutWidget2);
        usernameNotValidLabel->setObjectName(QString::fromUtf8("usernameNotValidLabel"));
        usernameNotValidLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(usernameNotValidLabel);


        retranslateUi(EditUser);

        QMetaObject::connectSlotsByName(EditUser);
    } // setupUi

    void retranslateUi(QDialog *EditUser)
    {
        EditUser->setWindowTitle(QCoreApplication::translate("EditUser", "Dialog", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditUser", "Cancel", nullptr));
        okButton->setText(QCoreApplication::translate("EditUser", "OK", nullptr));
        editUserMainLabel->setText(QCoreApplication::translate("EditUser", "Edit User", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("EditUser", "First Name:", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("EditUser", "Last Name: ", nullptr));
        userNameLabel->setText(QCoreApplication::translate("EditUser", "Username: ", nullptr));
        roleLabel->setText(QCoreApplication::translate("EditUser", "Role: ", nullptr));
        roleComboBox->setItemText(0, QCoreApplication::translate("EditUser", "Doctor", nullptr));
        roleComboBox->setItemText(1, QCoreApplication::translate("EditUser", "Nurse", nullptr));
        roleComboBox->setItemText(2, QCoreApplication::translate("EditUser", "Administrator", nullptr));

        firstNameEmptyLabel->setText(QCoreApplication::translate("EditUser", "Empty!", nullptr));
        lastNameEmptyLabel->setText(QCoreApplication::translate("EditUser", "Empty!", nullptr));
        usernameNotValidLabel->setText(QCoreApplication::translate("EditUser", "Not Valid!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditUser: public Ui_EditUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSER_H
