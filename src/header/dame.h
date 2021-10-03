#ifndef DAME_H
#define DAME_H
#include"piece.h"

class Dame : public Piece
{
public:
    Dame();
    Dame(int x, int y, Piece::Colour C);
    std::vector<intpair> possibleMoves (Piece*** );
};

#endif // DAME_H
