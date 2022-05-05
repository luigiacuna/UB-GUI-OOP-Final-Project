/********************************************************************************
** Form generated from reading UI file 'addeditpatient.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITPATIENT_H
#define UI_ADDEDITPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEditPatient
{
public:
    QLabel *currentPatientLabel;
    QWidget *layoutWidget;
    QVBoxLayout *medicineDurationLayout;
    QHBoxLayout *medincineLabels;
    QLabel *medicineLabelAssign;
    QLabel *intervalsLabel;
    QHBoxLayout *intervalsInput;
    QComboBox *medicineComboBox;
    QSpacerItem *horizontalSpacer;
    QComboBox *numberIntervals;
    QComboBox *hrsInterval;
    QWidget *layoutWidget1;
    QHBoxLayout *inputLayout;
    QVBoxLayout *patinetlabels;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *dobLabel;
    QLabel *genderLabel;
    QVBoxLayout *patientInputs;
    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *dobInputMaybe;
    QComboBox *genderComboBox;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QTableWidget *scheduleTableWidget;
    QHBoxLayout *selectionLabels;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *selectedPatientLabel;
    QComboBox *selectedPatientCombo;

    void setupUi(QDialog *AddEditPatient)
    {
        if (AddEditPatient->objectName().isEmpty())
            AddEditPatient->setObjectName(QString::fromUtf8("AddEditPatient"));
        AddEditPatient->resize(400, 618);
        currentPatientLabel = new QLabel(AddEditPatient);
        currentPatientLabel->setObjectName(QString::fromUtf8("currentPatientLabel"));
        currentPatientLabel->setGeometry(QRect(110, 30, 211, 20));
        layoutWidget = new QWidget(AddEditPatient);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 290, 371, 71));
        medicineDurationLayout = new QVBoxLayout(layoutWidget);
        medicineDurationLayout->setObjectName(QString::fromUtf8("medicineDurationLayout"));
        medicineDurationLayout->setContentsMargins(0, 0, 0, 0);
        medincineLabels = new QHBoxLayout();
        medincineLabels->setObjectName(QString::fromUtf8("medincineLabels"));
        medicineLabelAssign = new QLabel(layoutWidget);
        medicineLabelAssign->setObjectName(QString::fromUtf8("medicineLabelAssign"));

        medincineLabels->addWidget(medicineLabelAssign);

        intervalsLabel = new QLabel(layoutWidget);
        intervalsLabel->setObjectName(QString::fromUtf8("intervalsLabel"));
        intervalsLabel->setAlignment(Qt::AlignCenter);

        medincineLabels->addWidget(intervalsLabel);


        medicineDurationLayout->addLayout(medincineLabels);

        intervalsInput = new QHBoxLayout();
        intervalsInput->setObjectName(QString::fromUtf8("intervalsInput"));
        medicineComboBox = new QComboBox(layoutWidget);
        medicineComboBox->setObjectName(QString::fromUtf8("medicineComboBox"));

        intervalsInput->addWidget(medicineComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        intervalsInput->addItem(horizontalSpacer);

        numberIntervals = new QComboBox(layoutWidget);
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->addItem(QString());
        numberIntervals->setObjectName(QString::fromUtf8("numberIntervals"));

        intervalsInput->addWidget(numberIntervals);

        hrsInterval = new QComboBox(layoutWidget);
        hrsInterval->addItem(QString());
        hrsInterval->addItem(QString());
        hrsInterval->setObjectName(QString::fromUtf8("hrsInterval"));

        intervalsInput->addWidget(hrsInterval);


        medicineDurationLayout->addLayout(intervalsInput);

        layoutWidget1 = new QWidget(AddEditPatient);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 120, 371, 171));
        inputLayout = new QHBoxLayout(layoutWidget1);
        inputLayout->setObjectName(QString::fromUtf8("inputLayout"));
        inputLayout->setContentsMargins(0, 0, 0, 0);
        patinetlabels = new QVBoxLayout();
        patinetlabels->setObjectName(QString::fromUtf8("patinetlabels"));
        firstNameLabel = new QLabel(layoutWidget1);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));

        patinetlabels->addWidget(firstNameLabel);

        lastNameLabel = new QLabel(layoutWidget1);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));

        patinetlabels->addWidget(lastNameLabel);

        dobLabel = new QLabel(layoutWidget1);
        dobLabel->setObjectName(QString::fromUtf8("dobLabel"));

        patinetlabels->addWidget(dobLabel);

        genderLabel = new QLabel(layoutWidget1);
        genderLabel->setObjectName(QString::fromUtf8("genderLabel"));
        genderLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        patinetlabels->addWidget(genderLabel);


        inputLayout->addLayout(patinetlabels);

        patientInputs = new QVBoxLayout();
        patientInputs->setObjectName(QString::fromUtf8("patientInputs"));
        firstNameInput = new QLineEdit(layoutWidget1);
        firstNameInput->setObjectName(QString::fromUtf8("firstNameInput"));

        patientInputs->addWidget(firstNameInput);

        lastNameInput = new QLineEdit(layoutWidget1);
        lastNameInput->setObjectName(QString::fromUtf8("lastNameInput"));

        patientInputs->addWidget(lastNameInput);

        dobInputMaybe = new QLineEdit(layoutWidget1);
        dobInputMaybe->setObjectName(QString::fromUtf8("dobInputMaybe"));

        patientInputs->addWidget(dobInputMaybe);

        genderComboBox = new QComboBox(layoutWidget1);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName(QString::fromUtf8("genderComboBox"));

        patientInputs->addWidget(genderComboBox);


        inputLayout->addLayout(patientInputs);

        layoutWidget2 = new QWidget(AddEditPatient);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 370, 371, 226));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scheduleTableWidget = new QTableWidget(layoutWidget2);
        scheduleTableWidget->setObjectName(QString::fromUtf8("scheduleTableWidget"));

        verticalLayout->addWidget(scheduleTableWidget);

        selectionLabels = new QHBoxLayout();
        selectionLabels->setObjectName(QString::fromUtf8("selectionLabels"));
        okButton = new QPushButton(layoutWidget2);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        selectionLabels->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        selectionLabels->addWidget(cancelButton);


        verticalLayout->addLayout(selectionLabels);

        layoutWidget3 = new QWidget(AddEditPatient);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 70, 371, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        selectedPatientLabel = new QLabel(layoutWidget3);
        selectedPatientLabel->setObjectName(QString::fromUtf8("selectedPatientLabel"));

        horizontalLayout->addWidget(selectedPatientLabel);

        selectedPatientCombo = new QComboBox(layoutWidget3);
        selectedPatientCombo->setObjectName(QString::fromUtf8("selectedPatientCombo"));

        horizontalLayout->addWidget(selectedPatientCombo);


        retranslateUi(AddEditPatient);

        QMetaObject::connectSlotsByName(AddEditPatient);
    } // setupUi

    void retranslateUi(QDialog *AddEditPatient)
    {
        AddEditPatient->setWindowTitle(QCoreApplication::translate("AddEditPatient", "Dialog", nullptr));
        currentPatientLabel->setText(QCoreApplication::translate("AddEditPatient", "Patient Data this will add or edit", nullptr));
        medicineLabelAssign->setText(QCoreApplication::translate("AddEditPatient", "Medcine to Assign", nullptr));
        intervalsLabel->setText(QCoreApplication::translate("AddEditPatient", "Intervals", nullptr));
        numberIntervals->setItemText(0, QCoreApplication::translate("AddEditPatient", "1", nullptr));
        numberIntervals->setItemText(1, QCoreApplication::translate("AddEditPatient", "2", nullptr));
        numberIntervals->setItemText(2, QCoreApplication::translate("AddEditPatient", "3", nullptr));
        numberIntervals->setItemText(3, QCoreApplication::translate("AddEditPatient", "4", nullptr));
        numberIntervals->setItemText(4, QCoreApplication::translate("AddEditPatient", "5", nullptr));
        numberIntervals->setItemText(5, QCoreApplication::translate("AddEditPatient", "6", nullptr));
        numberIntervals->setItemText(6, QCoreApplication::translate("AddEditPatient", "7", nullptr));
        numberIntervals->setItemText(7, QCoreApplication::translate("AddEditPatient", "8", nullptr));
        numberIntervals->setItemText(8, QCoreApplication::translate("AddEditPatient", "9", nullptr));
        numberIntervals->setItemText(9, QCoreApplication::translate("AddEditPatient", "10", nullptr));
        numberIntervals->setItemText(10, QCoreApplication::translate("AddEditPatient", "11", nullptr));
        numberIntervals->setItemText(11, QCoreApplication::translate("AddEditPatient", "12", nullptr));

        hrsInterval->setItemText(0, QCoreApplication::translate("AddEditPatient", "Hours", nullptr));
        hrsInterval->setItemText(1, QCoreApplication::translate("AddEditPatient", "Days", nullptr));

        firstNameLabel->setText(QCoreApplication::translate("AddEditPatient", "First Name:", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("AddEditPatient", "Last Name:", nullptr));
        dobLabel->setText(QCoreApplication::translate("AddEditPatient", "DOB:", nullptr));
        genderLabel->setText(QCoreApplication::translate("AddEditPatient", "Gender:", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("AddEditPatient", "Male", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("AddEditPatient", "Female", nullptr));

        okButton->setText(QCoreApplication::translate("AddEditPatient", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddEditPatient", "Cancel", nullptr));
        selectedPatientLabel->setText(QCoreApplication::translate("AddEditPatient", "Patient:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditPatient: public Ui_AddEditPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITPATIENT_H
