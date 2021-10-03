#include "userdata.h"
#include "ui_userdata.h"
#include<QLabel>
#include<QString>
#include<QPushButton>
#include<QLine>
#include<QFont>
#include<QMessageBox>
#include<QLineEdit>
#include<QtDebug>
#include<userdata.h>
#include<widget.h>

userdata::userdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userdata)
{
    ui->setupUi(this);
    this->setWindowTitle("Data Eingabe");
    QLabel* firstnamelabel = new QLabel("First Name:",this);
                firstnamelabel->setMinimumSize(70,50);
     firstnamelabel->move(25,10);
        QLineEdit* firstnamelineEdit = new QLineEdit(this);
        firstnamelineEdit->setMinimumSize(200,20);
        firstnamelineEdit->move(100,25);
    //last name
        QLabel* lastnamelabel = new QLabel("Last Name:",this);
                lastnamelabel->setMinimumSize(70,70);
     lastnamelabel->move(25,45);
      QLineEdit* lastnamelineEdit = new QLineEdit(this);
       lastnamelineEdit->setMinimumSize(200,20);
        lastnamelineEdit->move(100,70);
        //city
        QLabel*city = new QLabel("city:",this);
                city->setMinimumSize(70,70);
                 city->move(50,95);
      QLineEdit *citytext = new QLineEdit(this);
       citytext->setMinimumSize(200,20);
        citytext->move(100,120);


       //grab info

        QFont submit("times",15, QFont::Bold );

        QPushButton* button = new QPushButton("Submit data",this);

        button->setFont(submit);
        button->move(20,220);



        connect(button,&QPushButton::clicked,[=](){

            QString firstname = firstnamelineEdit->text();
            QString lastname = lastnamelineEdit->text();
            QString city = citytext->text();
            if (!firstname.isEmpty() && !lastname.isEmpty()&& !city.isEmpty())
            {qDebug() << "First Name is :" << firstname;
             qDebug() <<" Last Name is :" << lastname;
              qDebug() <<" City is :" << city;}
         else QMessageBox::warning(this,"Error 404 ","Please give ALL data");

});
}
userdata::~userdata()
{
    delete ui;
}

void userdata::on_pushButton_clicked()
{
window0.show();

}
