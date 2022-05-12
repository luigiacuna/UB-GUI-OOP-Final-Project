#include "editpatient.h"
#include "ui_editpatient.h"

EditPatient::EditPatient(QString patient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPatient)
{
    ui->setupUi(this);
    ui->dobEdit->setDate(QDate::currentDate());
    //pushing items that are already established in the database
    ui->assignedNurseComboBox->addItems(listAvaliableNurses());
    ui->assignedNurseComboBox->setCurrentIndex(0);
    ui->medComboBox->addItems(listAvaliableMeds());
    ui->medComboBox->setCurrentIndex(0);
    ui->medComboBox->addItem("Add Medicine");
    //filling the patient combo box with the avaliable patients that have been created
    ui->patientComboBox->addItem("Select a patient");
    ui->patientComboBox->addItems(listAvaliablePatients());//to be grabbed from the patient data portion need to create db function
    ui->doctorComboBox->addItems(listAvaliableDoctors());
    ui->dateBeginInput->setDate(QDate::currentDate());
    ui->dateEndInput->setDate(QDate::currentDate());
    if(patient == "")//disbale all buttons at startup if no patient is passed in
    {
        ui->updateButton->setEnabled(false);
        ui->firstNameEdit->setEnabled(false);
        ui->lastNameEdit->setEnabled(false);
        ui->ageInput->setEnabled(false);
        ui->phoneNumberEdit->setEnabled(false);
        ui->genderComboBox->setEnabled(false);
        ui->dobEdit->setEnabled(false);
        ui->socialSecurityNumberInput->setEnabled(false);
        ui->doctorComboBox->setEnabled(false);
        ui->updateButton->setEnabled(false);
        ui->doctorComboBox->setCurrentIndex(-1);

        //disabling the add schedling buttons
        ui->assignedNurseComboBox->setCurrentIndex(-1);
        ui->assignedNurseComboBox->setEnabled(false);
        ui->medComboBox->setCurrentIndex(-1);
        ui->medComboBox->setEnabled(false);
        ui->dosageValueInNum->setEnabled(false);
        ui->dosageValueInUnits->setEnabled(false);
        ui->intervaValueNum->setEnabled(false);
        ui->intervalValueComboBox->setCurrentIndex(-1);
        ui->intervalValueComboBox->setEnabled(false);
        ui->dateBeginInput->setEnabled(false);
        ui->dateEndInput->setEnabled(false);
        ui->addToSchedule->setEnabled(false);
        ui->updateScheduleButton->setEnabled(false);
        ui->removeFromSchedule->setEnabled(false);


    }
    ui->scheduleView->verticalHeader()->setVisible(false);
    ui->scheduleView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->scheduleView->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->scheduleView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->scheduleView->setModel(showSchedule("",2));


    connect(ui->updateButton,SIGNAL(clicked()),this,SLOT(updateButtonPressed()));
    connect(ui->addToSchedule,SIGNAL(clicked()),this,SLOT(addButtonPressed()));
}

EditPatient::~EditPatient()
{
    delete ui;
}

void EditPatient::updateButtonPressed()
{
    qDebug()<<"Update button has been pressed";
    bool firstNameOK;
    bool lastNameOK;
    //now to check if the main stuff is not empty by chance
    if(ui->firstNameEdit->text().isEmpty())
    {
        ui->firstNameEdit->setPlaceholderText("Cannot be empty");
        ui->firstNameLabel->setText("First Name (*)");
        ui->firstNameLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->firstNameEdit->setPlaceholderText("");
        ui->firstNameLabel->setText("First Name");
        ui->firstNameLabel->setStyleSheet("font-weight:regular;color:black;");
        firstNameOK = true;
    }
    if(ui->lastNameEdit->text().isEmpty())
    {
        ui->lastNameEdit->setPlaceholderText("Cannot be empty");
        ui->lastNameLabel->setText("First Name (*)");
        ui->lastNameLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->lastNameEdit->setPlaceholderText("");
        ui->lastNameLabel->setText("First Name");
        ui->lastNameLabel->setStyleSheet("font-weight:regular;color:black;");
        lastNameOK = true;
    }


    if(firstNameOK == true && lastNameOK == true)
    {
        QString patientID = ui->patientComboBox->currentText().split(" ").at(0);//for the patient id to be correctly matched
        QString doctorID = ui->doctorComboBox->currentText().split(" ").at(0);
        updatePatient(patientID,ui->firstNameEdit->text(),ui->lastNameEdit->text(),ui->ageInput->text(),ui->phoneNumberEdit->text(),ui->genderComboBox->currentText(),ui->dobEdit->text(),ui->socialSecurityNumberInput->text(),doctorID);
    }


}

void EditPatient::addButtonPressed()
{
    qDebug()<<"Add to Schedule has been pressed";
    //when the add button is pressed it will push the apporiate schedule data to the db
    bool dosageNumOK;
    bool dosageValueUnitsOK;
    bool intervalValueNumOK;
    bool assignNurseOK;
    bool medOK;


    if(ui->dosageValueInNum->text().isEmpty())
    {
        ui->dosageValueInNum->setPlaceholderText("Cannot be empty");
        ui->dosageLabel->setText("Dosage (*)");
        ui->dosageLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->dosageValueInNum->setPlaceholderText("Value");
        ui->dosageLabel->setText("Dosage");
        ui->dosageLabel->setStyleSheet("font-weight:normal;color:black;");
        dosageNumOK=true;
    }

    if(ui->dosageValueInUnits->text().isEmpty())
    {
       ui->dosageValueInUnits->setPlaceholderText("Cannot be empty");
       ui->dosageLabel->setText("Dosage (*)");
       ui->dosageLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->dosageValueInUnits->setPlaceholderText("Units");
        ui->dosageLabel->setText("Dosage");
        ui->dosageLabel->setStyleSheet("font-weight:normal;color:black;");
        dosageValueUnitsOK=true;
    }

    if(ui->intervaValueNum->text().isEmpty())
    {
        ui->intervaValueNum->setPlaceholderText("Cannot be Empty");
        ui->intervalLabel->setText("Interval(*)");
        ui->intervalLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->intervaValueNum->setPlaceholderText("Value");
        ui->intervalLabel->setText("Interval(*)");
        ui->intervalLabel->setStyleSheet("font-weight:normal;color:black;");
        intervalValueNumOK=true;
    }
    if(ui->assignedNurseComboBox->currentText()=="")
    {
        ui->assignedNurseLabel->setText("Select Nurse(*)");
        ui->assignedNurseLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->assignedNurseLabel->setText("Assigned Nurse");
        ui->assignedNurseLabel->setStyleSheet("font-weight:normal;color:black;");
        assignNurseOK=true;
    }

    if(ui->medComboBox->currentText() == "")
    {
        ui->medLabel->setText("Select Medicine(*)");
        ui->medLabel->setStyleSheet("font-weight:bold;color:red;");
    }
    else
    {
        ui->medLabel->setText("Medicine");
        ui->medLabel->setStyleSheet("font-weight:normal;color:black;");
        medOK=true;
    }

   //now that all checks is done now to get specfics so it can be passed into the db function
   //Nurse ID, MedID, Patient ID, dosage in num, dosage in units, intervals in num, intervals in units
    if(dosageNumOK == true && dosageValueUnitsOK== true && intervalValueNumOK == true && assignNurseOK == true && medOK==true)
    {
        addSchedule(ui->patientComboBox->currentText().split(" ").at(0),          /*PatientID*/
                    ui->medComboBox->currentText().split(" ").at(0),              /*medID*/
                    ui->dosageValueInNum->text(),                                 /*dosage_in_num*/
                    ui->dosageValueInUnits->text(),                               /*dosage_units*/
                    ui->dateBeginInput->text(),                                   /*date_start*/
                    ui->dateEndInput->text(),                                     /*date_end*/
                    ui->assignedNurseComboBox->currentText().split(" ").at(0),    /*nurse_id*/
                    ui->intervaValueNum->text(),                                  /*interval_in_num*/
                    ui->intervalValueComboBox->currentText()                      /*interval_in_units*/
                    );
    }


}

void EditPatient::on_medComboBox_textActivated(const QString &arg1)
{
    //allows doctors to quiclky add medicine albeilt this quick action still have to follow the same rules as addMedicine class
        if(arg1 == "Add Medicine")
        {
           qDebug()<<"yah this i be looking for";
           bool ok;
           //QString addMedMsg = QInputDialog::getText(this,"Add Medicine","Add a medicine not on the list",QLineEdit::Normal,QDir::home().dirName(),&ok);
           QString addMedMsg = QInputDialog::getText(this,"Add Medicine","Add a medicine not on the list",QLineEdit::Normal,"",&ok);
           if(!addMedMsg.isEmpty())
           {
               if(listAvaliableMeds().contains(addMedMsg))
               {
                   QMessageBox::information(this,"Cannot Add","The medincine inputted cannot be inputeed, it already exist");
                   ui->medComboBox->setCurrentIndex(0);
               }
               else
               {
                   addMeds(addMedMsg);
                   ui->medComboBox->clear();
                   ui->medComboBox->addItems(listAvaliableMeds());
                   ui->medComboBox->addItem("Add Medicine");
                   ui->medComboBox->setCurrentText(addMedMsg);//need to fix back to set to newly added meds
               }
           }
           else
           {
               QMessageBox::information(this,"Empty","Nothing has been filled in boss");
               ui->medComboBox->setCurrentIndex(0);
           }

        }
        else
            qDebug()<<"nahh this aint the good stuff";
}


void EditPatient::on_patientComboBox_textActivated(const QString &arg1)
{
    QString currentSelection = ui->patientComboBox->currentText().split(" ").at(0);
    if(arg1 == "Select a patient")
    {
        ui->updateButton->setEnabled(false);
        //blank out all the inputs
        ui->firstNameEdit->setText("");
        ui->lastNameEdit->setText("");
        ui->ageInput->setText("");
        ui->phoneNumberEdit->setText("");
        ui->genderComboBox->setCurrentText("");
        ui->dobEdit->setDate(QDate::currentDate());
        ui->socialSecurityNumberInput->setText("");
        ui->doctorComboBox->setCurrentIndex(-1);
        //disable all the buttons
        ui->firstNameEdit->setEnabled(false);
        ui->lastNameEdit->setEnabled(false);
        ui->ageInput->setEnabled(false);
        ui->phoneNumberEdit->setEnabled(false);
        ui->genderComboBox->setEnabled(false);
        ui->dobEdit->setEnabled(false);
        ui->socialSecurityNumberInput->setEnabled(false);
        ui->doctorComboBox->setEnabled(false);
        ui->updateButton->setEnabled(false);
        //disabling the add schedling buttons
        ui->assignedNurseComboBox->setCurrentIndex(-1);
        ui->assignedNurseComboBox->setEnabled(false);
        ui->medComboBox->setCurrentIndex(-1);
        ui->medComboBox->setEnabled(false);
        ui->dosageValueInNum->setEnabled(false);
        ui->dosageValueInUnits->setEnabled(false);
        ui->intervaValueNum->setEnabled(false);
        ui->intervalValueComboBox->setCurrentIndex(-1);
        ui->intervalValueComboBox->setEnabled(false);
        ui->dateBeginInput->setEnabled(false);
        ui->dateEndInput->setEnabled(false);
        ui->addToSchedule->setEnabled(false);
        ui->removeFromSchedule->setEnabled(false);

        //fix up the schedule section back to stock
        ui->dosageValueInNum->setPlaceholderText("Value");
        ui->dosageValueInNum->setText("");
        ui->dosageLabel->setText("Dosage");
        ui->dosageLabel->setStyleSheet("font-weight:normal;color:black;");

        ui->dosageValueInUnits->setPlaceholderText("Units");
        ui->dosageValueInUnits->setText("");
        ui->dosageLabel->setText("Dosage");
        ui->dosageLabel->setStyleSheet("font-weight:normal;color:black;");

        ui->intervaValueNum->setPlaceholderText("Value");
        ui->intervaValueNum->setText("");
        ui->intervalLabel->setText("Interval(*)");
        ui->intervalLabel->setStyleSheet("font-weight:normal;color:black;");

        ui->assignedNurseLabel->setText("Assigned Nurse");
        ui->assignedNurseLabel->setStyleSheet("font-weight:normal;color:black;");

        ui->medLabel->setText("Medicine");
        ui->medLabel->setStyleSheet("font-weight:normal;color:black;");
        ui->scheduleView->setModel(showSchedule("",2));


    }
    else
    {
        qDebug()<<ui->medComboBox->currentText();//ok comes out as blank see if i can use that to my advantage
        qDebug()<<ui->medComboBox->currentText();
        ui->updateScheduleButton->setEnabled(false);
        ui->removeFromSchedule->setEnabled(false);
        ui->firstNameEdit->setEnabled(true);
        ui->lastNameEdit->setEnabled(true);
        ui->ageInput->setEnabled(true);
        ui->phoneNumberEdit->setEnabled(true);
        ui->genderComboBox->setEnabled(true);
        ui->dobEdit->setEnabled(true);
        ui->socialSecurityNumberInput->setEnabled(true);
        ui->doctorComboBox->setEnabled(true);
        ui->updateButton->setEnabled(true);
        QStringList data = selectedPatientInfo(currentSelection);
        QDate dob= QDate::fromString(data[5],"yyyy-MM-dd");
        qDebug()<<"DOB output "<<dob;
        ui->firstNameEdit->setText(data[0]);
        ui->lastNameEdit->setText(data[1]);
        ui->ageInput->setText(data[2]);
        ui->phoneNumberEdit->setText(data[3]);
        ui->genderComboBox->setCurrentText(data[4]);
        ui->dobEdit->setDate(dob);
        ui->socialSecurityNumberInput->setText(data[6]);
        ui->updateButton->setEnabled(true);
        ui->doctorComboBox->setCurrentText(data[7]);
        //disabling the add schedling buttons
        ui->assignedNurseComboBox->setCurrentIndex(-1);//need to update
        ui->assignedNurseComboBox->setEnabled(true);
        ui->medComboBox->setCurrentIndex(-1);//need to update
        ui->medComboBox->setEnabled(true);
        ui->dosageValueInNum->setEnabled(true);
        ui->dosageValueInNum->setPlaceholderText("Value");
        ui->dosageValueInUnits->setEnabled(true);
        ui->dosageValueInUnits->setPlaceholderText("Units");
        ui->intervaValueNum->setEnabled(true);
        ui->intervaValueNum->setPlaceholderText("Value");
        ui->intervalValueComboBox->setCurrentIndex(-1);//need to update
        ui->intervalValueComboBox->setEnabled(true);
        ui->dateBeginInput->setEnabled(true);
        ui->dateEndInput->setEnabled(true);
        ui->addToSchedule->setEnabled(true);
        //now that all inputs are disable and enabled accoridiately grab the scedule for that particular partient
        ui->scheduleView->setModel(showSchedule(ui->patientComboBox->currentText().split(" ").at(0),1));
    }
}




