#ifndef BAUER_H
#define BAUER_H
#include"piece.h"



class Bauer : public Piece
{
public:
    Bauer();
    Bauer(int x, int y, Piece::Colour C);
    std::vector<intpair> possibleMoves (Piece***);
    //void setenpassant(intpair a) {enpassant=a;};

//private:
    //std::pair<int,int> enpassant=intpair(0,0);
};

#endif // BAUER_H
