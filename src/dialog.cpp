#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Bauerumwandlung");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    emit QueenSignal();
    close();
}

void Dialog::on_pushButton_2_clicked()
{
    emit TurmSignal();
    close();
}

void Dialog::on_pushButton_3_clicked()
{
    emit SpringerSignal();
    close();
}

void Dialog::on_pushButton_4_clicked()
{
    emit LaueferSignal();
    close();
}
