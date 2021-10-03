#include "piece.h"

Piece::Piece(int x,int y, Colour c):_X(x),_Y(y),_Col(c)
{

}


bool inRange(int x, int y){
return x>=0 && x<=7 && y>=0 && y<=7;
}
