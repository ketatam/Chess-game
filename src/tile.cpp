#include "tile.h"
#include"chessboard.h"
#include<iostream>
#include"dialog.h"
#include"playerwhitewins.h"
#include"playerblackwins.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>

std::vector<intpair> v;
extern chessBoard Board;
extern Tile* click1;
extern int turn;
extern Tile* tile[8][8];
void validate(Tile *temp,int c);

bool istSpielZuEnde (std::vector<Piece*> crew);

void Tile::mousePressEvent(QMouseEvent *)
{
    validate(this,++count);
    return;
}


bool detectEnPassant (char c,  int y, int tox, int toy){
    if (c=='P' && toy!=y && tile[tox][toy]->piece==0)
        return true;
    else return false;

}


bool detectKleineRochade (char c,  int y,  int toy){
    if(c == 'K' && toy-y == 2)
        return true;
    else return false;

}
bool detectGrosseRochade (char c,  int y,  int toy){
    if(c == 'K' && toy-y == -2)
        return true;
    else return false;
}

void Tile::display(char elem)
{
    this->pieceName=elem;

    if(this->pieceColor && this->piece)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/pawn_white.svg"));
            break;
        case 'R': this->setPixmap(QPixmap(":/rook_white.svg"));
            break;
        case 'H': this->setPixmap(QPixmap(":/knight_white.svg"));
            break;
        case 'K': this->setPixmap(QPixmap(":/king_white.svg"));
            break;
        case 'Q': this->setPixmap(QPixmap(":/queen_white.svg"));
            break;
        case 'B': this->setPixmap(QPixmap(":/bishop_white.svg"));
            break;
        }
    }

    else if(this->piece)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/pawn_black.svg"));
            break;
        case 'R': this->setPixmap(QPixmap(":/rook_black.svg"));
            break;
        case 'H': this->setPixmap(QPixmap(":/knight_black.svg"));
            break;
        case 'K': this->setPixmap(QPixmap(":/king_black.svg"));
            break;
        case 'Q': this->setPixmap(QPixmap(":/queen_black.svg"));
            break;
        case 'B': this->setPixmap(QPixmap(":/bishop_black.svg"));
            break;
        }
    }
    else
        this->clear();
}




void Tile::tileDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background-color: rgb(160,82,45);}:hover{background-color: rgb(76,153,0);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(245,222,179);}:hover{background-color: rgb(102,204,0);}");
}

int Tile::count_init = 0;

void validate(Tile *temp,int c) {
    //1. Click
    if (c==1) {
        //ungültiger 1. Click (leeres Feld oder not my turn)
        if (!(temp->piece) || temp->pieceColor!=turn) {
            /* for (auto i : v) {
                if (i.first != -1) {
                if (tile[7 - i.first][i.second]->tileColor)
                    tile[7 - i.first][i.second]->setStyleSheet("QLabel {background-color: rgb(160,82,45);}:hover{background-color: rgb(76,153,0);}");
                else
                    tile[7 - i.first][i.second]->setStyleSheet("QLabel {background-color: rgb(245,222,179);}:hover{background-color: rgb(102,204,0);}");}
            }*/
            count=0;return;
        }
        // Gültiger 1. Click
        // Mögliche züge anzeigen
        v = Board.Field[7-temp->row][temp->col]->possibleMoves(Board.Field);
        //enpassant?
        if (std::find(Board.enpassantcrew.begin(),Board.enpassantcrew.end(),Board.Field[7-temp->row][temp->col])!=Board.enpassantcrew.end())
            v.push_back(Board.enpassant);
        for (auto&& i : v) {
            if (Board.ifMovePutsKingInDanger(Board.Field[7-temp->row][temp->col],i.first,i.second)) {
                i.first = -1;
            }

        }
        //kurze Rochade?
        if (Board.detectKurzeRochade(Board.Field[7-temp->row][temp->col])!= intpair(-1,-1)) {
            v.push_back(Board.detectKurzeRochade(Board.Field[7-temp->row][temp->col]));
        }

        //lange Rochade?
        if (Board.detectLangeRochade(Board.Field[7-temp->row][temp->col])!= intpair(-1,-1)) {
            v.push_back(Board.detectLangeRochade(Board.Field[7-temp->row][temp->col]));
        }
        // jetzt anzeigen
        for (auto i : v) {
            if (i.first != -1) {
                if (tile[7 - i.first][i.second]->tileColor)
                    tile[7 - i.first][i.second]->setStyleSheet("QLabel {background-color: rgb(76,153,0);}:hover{background-color: rgb(76,153,0);}");
                else
                    tile[7 - i.first][i.second]->setStyleSheet("QLabel {background-color: rgb(102,204,0);}:hover{background-color: rgb(102,204,0);}");
            }
        }
        // 1. Click speicehrn
        click1 = temp;
    } else { // 2. Click
        // die angezeigeten Züge wieder ausbleden
        for (auto i : v) {
            qDebug() << "Tiles initialized " << Tile::count_init;
            if (i.first != -1) {
                if (tile[7 - i.first][i.second]->tileColor)
                    tile[7 - i.first][i.second]->setStyleSheet("QLabel {background-color: rgb(160,82,45);}:hover{background-color: rgb(76,153,0);}");
                else
                    tile[7 - i.first][i.second]->setStyleSheet("QLabel {background-color: rgb(245,222,179);}:hover{background-color: rgb(102,204,0);}");}

        }
        // ob Zug möglich?
        bool test = Board.move(Board.Field[7-click1->row][click1->col],7-temp->row,temp->col);
        if (!test) {
            // Zug unmöglich ==> erneut versuchen
            count=0;return; }
        else { // Zug is möglich!

            // enpassant?
            if (detectEnPassant(click1->pieceName,click1->col,temp->row,temp->col)){
                temp->piece=1;
                temp->pieceColor = click1->pieceColor;
                temp->display(click1->pieceName);

                click1->piece=0;
                click1->display('x');

                tile[click1->row][temp->col]->piece=0;
                tile[click1->row][temp->col]->display('x');

                turn=1-turn;
                count=0;

                return;
            }

            // kurze Rochade?
            if (detectKleineRochade(click1->pieceName,click1->col,temp->col)) {

                temp->piece=click1->piece;
                temp->pieceColor = click1->pieceColor;
                temp->display(click1->pieceName);

                click1->piece=0;
                click1->display('x');

                tile[click1->row][click1->col+1]->piece = tile[click1->row][click1->col+3]->piece;
                tile[click1->row][(click1->col)+1]->pieceColor = tile[click1->row][click1->col+3]->pieceColor;
                tile[click1->row][click1->col+1]->display(tile[click1->row][click1->col+3]->pieceName);

                tile[click1->row][click1->col+3]->piece = 0;
                tile[click1->row][click1->col+3]->display('x');

                turn=1-turn;
                count=0;

                return;
            }

            // lange Rochade
            if (detectGrosseRochade(click1->pieceName,click1->col,temp->col)) {

                temp->piece=click1->piece;
                temp->pieceColor = click1->pieceColor;
                temp->display(click1->pieceName);

                click1->piece=0;
                click1->display('x');

                tile[click1->row][click1->col-1]->piece = tile[click1->row][click1->col-4]->piece;
                tile[click1->row][(click1->col)-1]->pieceColor = tile[click1->row][click1->col-4]->pieceColor;
                tile[click1->row][click1->col-1]->display(tile[click1->row][click1->col-4]->pieceName);

                tile[click1->row][click1->col-4]->piece = 0;
                tile[click1->row][click1->col-4 ]->display('x');

                turn=1-turn;
                count=0;

                return;
            }

            // Bauer in letzter Reihe? ==> transformiert
            if ( inRange(7-click1->row,click1->col) && tile[click1->row][click1->col]->pieceName == 'P'
                 && (temp->row == 0 || temp->row== 7)) {

                Dialog ch;

                // zu Dame
                QObject::connect(&ch, &Dialog::QueenSignal,[&](){
                    temp->piece =1;
                    temp->pieceColor = click1->pieceColor;
                    temp->display('Q');
                    click1->piece=0;
                    click1->display('x');
                    turn=1-turn;
                    count=0;
                    Board.transformBauer(Board.Field[7-click1->row][click1->col],7-temp->row,temp->col,"Dame");
                    return;
                });

                // zu Turm
                QObject::connect(&ch, &Dialog::TurmSignal,[&](){
                    temp->piece =1;
                    temp->pieceColor = click1->pieceColor;
                    temp->display('R');
                    click1->piece=0;
                    click1->display('x');
                    turn=1-turn;
                    count=0;
                    Board.transformBauer(Board.Field[7-click1->row][click1->col],7-temp->row,temp->col,"Turm");
                    return;
                });

                // zu Springer
                QObject::connect(&ch, &Dialog::SpringerSignal,[&](){
                    temp->piece =1;
                    temp->pieceColor = click1->pieceColor;
                    temp->display('H');
                    click1->piece=0;
                    click1->display('x');
                    turn=1-turn;
                    count=0;
                    Board.transformBauer(Board.Field[7-click1->row][click1->col],7-temp->row,temp->col,"Springer");
                    return;
                });

                // zu Läufer
                QObject::connect(&ch, &Dialog::LaueferSignal,[&](){
                    temp->piece =1;
                    temp->pieceColor = click1->pieceColor;
                    temp->display('B');
                    click1->piece=0;
                    click1->display('x');
                    turn=1-turn;
                    count=0;
                    Board.transformBauer(Board.Field[7-click1->row][click1->col],7-temp->row,temp->col,"Laeufer");
                    return;
                });

                ch.exec();
                return;
            }

            // ganz normaler Zug
            // Figur an der neuen Position anzeigen
            temp->piece=click1->piece;
            temp->pieceColor = click1->pieceColor;
            temp->display(click1->pieceName);

            // Figur an der alten Position löschen
            click1->piece=0;
            click1->display('x');


            // moving sound!!!!!!!!

            QMediaPlayer* music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/moving action.mp3"));
            music->play();


            // next turn
            turn=1-turn;
            count=0;
            if (turn == 1) {
                bool spielBeendet = istSpielZuEnde(Board.blackCrew);
                if (spielBeendet) {
                    PlayerBlackWins pl;
                    pl.exec();
                }
            } else if (turn == 0){
                bool spielBeendet = istSpielZuEnde(Board.whiteCrew);
                if (spielBeendet) {
                    PlayerWhiteWins pl;
                    pl.exec();
                }
            }
        }


    }
}

bool istSpielZuEnde (std::vector<Piece*> crew) {
    for (auto i: crew) {
        if (i->getX() == -1) continue;
        std::vector<intpair> p = i->possibleMoves(Board.Field);
        for (auto j : p) {
            if (!Board.ifMovePutsKingInDanger(i,j.first,j.second))
                return false;
        }
    }
    return true;
}



