#ifndef KOENIG_H
#define KOENIG_H
#include "piece.h"

class Koenig : public Piece
{
public:
    Koenig();
    Koenig(int x, int y, Piece::Colour C);
    std::vector<intpair> possibleMoves (Piece*** F );
};

#endif // KOENIG_H
