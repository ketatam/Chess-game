#include "userinterface.h"
#include "ui_userinterface.h"
#include"widget.h"
#include<QPushButton>
#include<QAction>
#include<QPixmap>
#include<QLabel>
#include<QDialog>
#include"tile.h"
#include"userdata.h"
#include<QMessageBox>

Userinterface::Userinterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userinterface)
{
    ui->setupUi(this);
    this->setWindowTitle("CHESS GAME Gruppe1");
    QPixmap bkgnd(":/background1.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    QPixmap pix(":/horse.png");
    ui->label_2->setPixmap(pix.scaled(120,120,Qt::KeepAspectRatio));

}

Userinterface::~Userinterface()
{
    delete ui;
}


void Userinterface::on_pushButton_clicked()
{
 window.show();
}

void Userinterface::on_pushButton_2_clicked()
{
    window1.show();
    window.close();

}
