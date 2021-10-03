#ifndef SPRINGER_H
#define SPRINGER_H
#include "piece.h"

class Springer : public Piece
{
public:
    Springer();
    Springer(int x, int y, Piece::Colour C=W);
    std::vector<intpair> possibleMoves (Piece*** );
};

#endif // SPRINGER_H
