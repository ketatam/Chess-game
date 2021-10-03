#include "koenig.h"



Koenig::Koenig(int x, int y, Piece::Colour C):Piece::Piece(x,y,C) {
    who="Koenig";
}


std::vector<intpair> Koenig::possibleMoves (Piece*** F){
   std::vector<intpair> v;
   for ( auto i : {  intpair(getX(),getY()+1),
                    intpair(getX()-1,getY()+1),
                    intpair(getX()-1,getY()),
                    intpair(getX()-1,getY()-1),
                    intpair(getX(),getY()-1),
                    intpair(getX()+1,getY()-1),
                    intpair(getX()+1,getY()),
                    intpair(getX()+1,getY()+1)       })
       if (inRange(i.first,i.second) && (F[i.first][i.second]==0 || F[i.first][i.second]->getColour()!=getColour()))
       v.push_back(i);





   return v;

}
