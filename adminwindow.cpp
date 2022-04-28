#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QMessageBox>

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    ui->editUser->setEnabled(false);
    ui->DeleteUser->setEnabled(false);
    ui->resetUserPasswordButton->setEnabled(false);
    //setting properties of the username view
    ui->usernameView->verticalHeader()->setVisible(false);
    ui->usernameView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//fit all the contents of the sql query to fit on the table width
    ui->usernameView->setSelectionBehavior(QAbstractItemView::SelectItems);//allows only one item to be selected at a time
    ui->usernameView->setSelectionMode(QAbstractItemView::SingleSelection);//whatever was selected becomes deselectd and the new item clicked becomes seleceted

    //ui->usernameView->setHorizontalHeaderLabels()//pretty up the headers later for that
    ui->usernameView->setModel(db.adminTable(1));//this will pull only the usernames and make that selectable

    //setting properties of the everything else view
    ui->everythingElse->verticalHeader()->setVisible(false);
    ui->everythingElse->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->everythingElse->setSelectionMode(QAbstractItemView::NoSelection);
    ui->everythingElse->setModel(db.adminTable(2));


    //QTimer to handle updating the label with the current date and time
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    QString msg = "Logged in as: "+val;
    ui->statusbar->showMessage("Logged in as: ",0);
    ui->statusbar->addPermanentWidget(ui->currrenTimeLabel);
    ui->statusbar->addPermanentWidget(ui->actualTimeLabel);




    connect(ui->resetUserPasswordButton,SIGNAL(clicked()),this,SLOT(startResetUser()));

    //connect for editing a user
    connect(ui->editUser,SIGNAL(clicked()),this,SLOT(editUser()));


    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(about()));
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::about()
{
    QMessageBox::information(this,"Information","This program is proudly created by a girl and two niggas for the GUI and OOP Final Project");
}

void AdminWindow::updateTime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString timeText = time.toString("ddd MMMM d hh : mm : ss");
    ui->actualTimeLabel->setText(timeText);
}

void AdminWindow::startResetUser()//was going to be lazy and use QInputDialog and use one input but couldn't control cancel button sigh...
{
    //going to open a new class just to reset a password that feels so ineffcient but oh well going to code it right with two inputs and verify
    ResetPassword *reset=new ResetPassword();
    reset->exec();
}

void AdminWindow::editUser()
{
    //this slot will pass in all the selected user info and pass in the editUser Class
    EditUser edit(val);
    edit.setModal(true);
    edit.exec();

}

//had to use the auto connect cause like i couldn't figure out to write it lol idk
void AdminWindow::on_usernameView_activated(const QModelIndex &index)
{
    //just to see if i can pass this for the other push buttons
    val = ui->usernameView->model()->data(index).toString();
    qDebug()<<val;
    ui->editUser->setEnabled(true);
    ui->DeleteUser->setEnabled(true);
    ui->resetUserPasswordButton->setEnabled(true);
    //renable the buttons here so the admin can either edit or reset the selected user's account
}

//Delets a user that is selected
void AdminWindow::on_DeleteUser_clicked()
{
    QModelIndexList ids;
    ids = ui->usernameView->selectionModel()->selectedRows();

    for(int i = 0; i < ids.size(); i++)
    {
        val = ui->usernameView->model()->data(ui->usernameView->model()->index(ids[i].data().toInt() - 1,0)).toString();
        //Uncomment this to acutally delete a user
        //db.deleteUser(val);
        qDebug()<<val;
    }

}
