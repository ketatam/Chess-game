#ifndef LAEUFER_H
#define LAEUFER_H
#include"piece.h"

class Laeufer : public Piece
{
public:
    Laeufer();
    Laeufer(int x, int y, Piece::Colour C);
    std::vector<intpair> possibleMoves (Piece*** );
};

#endif // LAEUFER_H
