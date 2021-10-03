#ifndef TURM_H
#define TURM_H
#include "piece.h"

class Turm : public Piece
{
public:
    Turm();
    Turm(int x, int y, Piece::Colour C);
    std::vector<intpair> possibleMoves (Piece*** );
};

#endif // TURM_H
