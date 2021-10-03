#include "dame.h"

Dame::Dame(int x, int y, Piece::Colour C):Piece::Piece(x,y,C)
{
    who = "Dame";
}

std::vector<intpair> Dame::possibleMoves (Piece*** F){
    std::vector<intpair> v;

    int i=1;
    do {
    if( inRange(getY()+i) && ( F[getX()][getY()+i]==0 || F[getX()][getY()+i]->getColour()!=getColour() ) ) {
        v.push_back(intpair(getX(),getY()+i));
        if (F[getX()][getY()+i]!=0) break;
        ++i;
        }
    else
        break;
    }while(true);

    i=1;
    do {
    if( inRange(getY()-i) && ( F[getX()][getY()-i]==0 || F[getX()][getY()-i]->getColour()!=getColour() ) ) {
        v.push_back(intpair(getX(),getY()-i));
        if (F[getX()][getY()-i]!=0) break;
        ++i;
        }
    else
        break;
    }while(true);

    i=1;
    do {
    if( inRange(getX()+i) && ( F[getX()+i][getY()]==0 || F[getX()+i][getY()]->getColour()!=getColour() ) ) {
        v.push_back(intpair(getX()+i,getY()));
        if (F[getX()+i][getY()]!=0) break;
        ++i;
        }
    else
        break;
    }while(true);


    i=1;
    do {
    if( inRange(getX()-i) && ( F[getX()-i][getY()]==0 || F[getX()-i][getY()]->getColour()!=getColour() ) ) {
        v.push_back(intpair(getX()-i,getY()));
        if (F[getX()-i][getY()]!=0) break;
        ++i;
        }
    else
        break;
    }while(true);


            i=1;
        do {
        if( inRange(getX()+i,getY()+i) && ( F[getX()+i][getY()+i]==0 || F[getX()+i][getY()+i]->getColour()!=getColour() ) ) {
            v.push_back(intpair(getX()+i,getY()+i));
            if (F[getX()+i][getY()+i]!=0) break;
            ++i;
            }
        else
            break;
        }while(true);

        i=1;
        do {
        if( inRange(getX()-i,getY()+i) && ( F[getX()-i][getY()+i]==0 || F[getX()-i][getY()+i]->getColour()!=getColour() ) ) {
            v.push_back(intpair(getX()-i,getY()+i));
            if (F[getX()-i][getY()+i]!=0) break;
            ++i;
            }
        else
            break;
        }while(true);

        i=1;
        do {
        if( inRange(getX()-i,getY()-i) && ( F[getX()-i][getY()-i]==0 || F[getX()-i][getY()-i]->getColour()!=getColour() ) ) {
            v.push_back(intpair(getX()-i,getY()-i));
            if (F[getX()-i][getY()-i]!=0) break;
            ++i;
            }
        else
            break;
        }while(true);


        i=1;
        do {
        if( inRange(getX()+i,getY()-i) && ( F[getX()+i][getY()-i]==0 || F[getX()+i][getY()-i]->getColour()!=getColour() ) ) {
            v.push_back(intpair(getX()+i,getY()-i));
            if (F[getX()+i][getY()-i]!=0) break;
            ++i;
            }
        else
            break;
        }while(true);

    return v;
}

