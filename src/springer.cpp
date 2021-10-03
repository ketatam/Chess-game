#include "springer.h"

Springer::Springer(int x, int y, Piece::Colour C):Piece::Piece(x,y,C)
{
    who="Springer";
}


std::vector<intpair> Springer::possibleMoves(Piece*** F){

std::vector<intpair> v;
for (auto i : { intpair(getX()+2,getY()+1),
                intpair(getX()+1,getY()+2),
                intpair(getX()-1,getY()+2),
                intpair(getX()-2,getY()+1),
                intpair(getX()-2,getY()-1),
                intpair(getX()-1,getY()-2),
                intpair(getX()+1,getY()-2),
                intpair(getX()+2,getY()-1), })
if (inRange(i.first,i.second) && (F[i.first][i.second]==0 || F[i.first][i.second]->getColour()!=getColour()))
v.push_back(i);
return v;


}
