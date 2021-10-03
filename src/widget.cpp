#include "widget.h"
#include "ui_widget.h"
#include"tile.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
extern Tile *tile[8][8];
void chessBoard0(QWidget *baseWidget, Tile *tile[8][8]);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
this->setWindowTitle("Chess Game");
    chessBoard0(this,tile);
    QPixmap bkgnd(":/background.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);



}

Widget::~Widget()
{
    delete ui;
}




