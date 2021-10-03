#include "bauer.h"


Bauer::Bauer(int x, int y, Piece::Colour C):Piece::Piece(x,y,C)
{
    who="Bauer";
}

std::vector<intpair> Bauer::possibleMoves ( Piece*** F ) {
    std::vector<intpair> v;
    if(getColour()==W) {
        if (F[getX()-1][getY()+1]!=0 && inRange(getX()-1,getY()+1) && F[getX()-1][getY()+1]->getColour()==S )
            v.push_back(intpair(getX()-1,getY()+1));
        if (F[getX()-1][getY()-1]!=0 && inRange(getX()-1,getY()-1) && F[getX()-1][getY()-1]->getColour()==S )
            v.push_back(intpair(getX()-1,getY()-1));
        if ( F[getX()-1][getY()]==0 )
            v.push_back(intpair(getX()-1,getY()));
        if ( getX()==6 && F[getX()-1][getY()]==0 && F[getX()-2][getY()]==0 )
            v.push_back(intpair(getX()-2,getY()));

    } else {
        if (F[getX()+1][getY()+1]!=0 && inRange(getX()+1,getY()+1) && F[getX()+1][getY()+1]->getColour()==W )
            v.push_back(intpair(getX()+1,getY()+1));
        if (F[getX()+1][getY()-1]!=0 && inRange(getX()+1,getY()-1) && F[getX()+1][getY()-1]->getColour()==W )
            v.push_back(intpair(getX()+1,getY()-1));
        if ( F[getX()+1][getY()]==0 )
            v.push_back(intpair(getX()+1,getY()));
        if ( getX()==1 && F[getX()+1][getY()]==0 && F[getX()+2][getY()]==0 )
            v.push_back(intpair(getX()+2,getY()));

    }
return v;
}
