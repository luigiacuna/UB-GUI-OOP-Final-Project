#include "addmedicine.h"
#include "ui_addmedicine.h"

AddMedicine::AddMedicine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMedicine)
{
    ui->setupUi(this);
    ui->removeMedsButton->setEnabled(false);
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(okButtonPressed()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancelButtonPressed()));
    connect(ui->removeMedsButton,SIGNAL(clicked()),this,SLOT(removeButtonPressed()));
    ui->avaliableMedsView->verticalHeader()->setVisible(false);
    ui->avaliableMedsView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->avaliableMedsView->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->avaliableMedsView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->avaliableMedsView->setModel(showAvaliableMeds());
}

AddMedicine::~AddMedicine()
{
    delete ui;
}

void AddMedicine::okButtonPressed()
{
    if(!ui->addMedsInput->text().isEmpty())
    {
        if(listAvaliableMeds().contains(ui->addMedsInput->text()))
            QMessageBox::information(this,"Adding Existing Meds","The medicine inputted already exists");
        else
        {
            addMeds(ui->addMedsInput->text());
            ui->avaliableMedsView->setModel(showAvaliableMeds());
        }
    }
    else
    {
        QMessageBox::information(this,"No Medicine Added","Nothing is inputted");
    }
}

void AddMedicine::removeButtonPressed()
{
    removeMed(medSelected);
    ui->avaliableMedsView->setModel(showAvaliableMeds());
}

void AddMedicine::cancelButtonPressed()
{
    this->close();
}



void AddMedicine::on_avaliableMedsView_activated(const QModelIndex &index)
{
    medSelected = ui->avaliableMedsView->model()->data(index).toString();
    qDebug()<<"Medicine selected is "<<medSelected;
    ui->removeMedsButton->setEnabled(true);
}

