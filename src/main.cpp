#include "widget.h"
#include"tile.h"
#include <QApplication>
#include"chessboard.h"
#include"userinterface.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QtDebug>
chessBoard Board;
//void chessBoard0(QWidget *baseWidget, Tile *tile[8][8]);
int count=0,turn=1;
Tile* click1=0;
Tile *tile[8][8] = { { NULL } };


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Userinterface w;






    w.setGeometry(0,0,800,600);


    w.show();

    return a.exec();
}




