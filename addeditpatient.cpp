#include "addeditpatient.h"
#include "ui_addeditpatient.h"

AddEditPatient::AddEditPatient(int senario,QString username,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditPatient)
{
    ui->setupUi(this);
    doctoruser = username;
    //this list all the avaliable meds that are avaliable for prescribing to a patient
    ui->medicineComboBox->addItems(listAvaliableMeds());
    ui->nurseAssignComboBox->addItems(listAvaliableNurses());
    //if in the case there is a med that is not listed allow the user to choose the option "Add Medicine" to quickly add one of course within the boundaries set by addMedicine class
    ui->medicineComboBox->addItem("Add Medicine");
    connect(ui->createButton,SIGNAL(clicked()),this,SLOT(openSenarioTwo()));

    if(senario == 1)
    {
        //This will imply that the doctor wants to create a new patient
        //hide the patient selection combo box
         ui->selectedPatientLabel->hide();
         ui->selectedPatientCombo->hide();
         //grey out the medicine addition stuff and some other stuff to make everything compact and remove dead space that is not used at that stage
         ui->dosageInt->hide();
         ui->dosageLabel->hide();
         ui->dosageUnits->hide();
         ui->intervalComboBox->hide();
         ui->intervalValue->hide();
         ui->medicineComboBox->hide();
         ui->dosageLabel->hide();
         ui->intervalsLabel->hide();
         ui->medicineLabelAssign->hide();
         ui->scheduleTableWidget->hide();
         ui->addToSchedule->hide();
         setGeometry(0,0,311,336);
         //now on the Create button do checks and go to senario 2




         //do fancy stuff
    }
    else if(senario == 2)

    {
        //This implies that the doctor wants to edit an existing patient
        //This will change the ok button to say update
        //a combo box will be viewable allowing the doctor to pick which patient to edit
        ui->createButton->hide();
        //do fancy stuff
    }

    /*The plan for this class is like this, eventhough this class is being shared by two buttons since both of them share 99% of code
     * The class will work this
     * 1. If the user clicks on the add patient button the patient selection combo box will be hidden and adding meds will be hidden however the addition of an add button will in placed. It is like this so a patient can be without neccessarily making a sceduele
     * 2. However if a patient is created and this add button will be hidden and removed from play, the patient selection box is shown is used it will convert to edit mode as if the patient was already there to begin with
     * */
}

AddEditPatient::~AddEditPatient()
{
    delete ui;
}

void AddEditPatient::openSenarioTwo()
{
    new AddEditPatient(2,doctoruser);
    this->close();
}

void AddEditPatient::on_medicineComboBox_textActivated(const QString &arg1)//using auto connect cause i couldn't get it working on my own lol
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
               ui->medicineComboBox->setCurrentIndex(0);
           }
           else
           {
               addMeds(addMedMsg);
               ui->medicineComboBox->addItems(listAvaliableMeds());
               ui->medicineComboBox->setCurrentText(addMedMsg);
           }
       }
       else
       {
           QMessageBox::information(this,"Empty","Nothing has been filled in boss");
           ui->medicineComboBox->setCurrentIndex(0);
       }

    }
    else
        qDebug()<<"nahh this aint the good stuff";
}

