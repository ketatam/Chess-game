#include "chessboard.h"

chessBoard::chessBoard() /*: Field(std::vector<std::vector<Piece*>>(std::vector<Piece*>(nullptr, 8), 8))*/
{
     Field = new Piece **[8];
    for(int i=0;i<=7;++i)
        Field[i] = new Piece*[8];

    for(int i=0;i<=7;++i)
        for(int j=0;j<=7;++j)
            Field[i][j]=0;

    Field[6][0]=&WB1;Field[6][1]=&WB2;Field[6][2]=&WB3;Field[6][3]=&WB4;
    Field[6][4]=&WB5;Field[6][5]=&WB6;Field[6][6]=&WB7;Field[6][7]=&WB8;
    Field[1][0]=&SB1;Field[1][1]=&SB2;Field[1][2]=&SB3;Field[1][3]=&SB4;
    Field[1][4]=&SB5;Field[1][5]=&SB6;Field[1][6]=&SB7;Field[1][7]=&SB8;
    Field[7][1]=&WS1;Field[7][6]=&WS2;Field[0][1]=&SS1;Field[0][6]=&SS2;
    Field[7][0]=&WT1;Field[7][7]=&WT2;Field[0][0]=&ST1;Field[0][7]=&ST2;
    Field[7][2]=&WL1;Field[7][5]=&WL2;Field[0][2]=&SL1;Field[0][5]=&SL2;
    Field[7][3]=&WD;Field[0][3]=&SD;
    Field[7][4]=&WK; Field[0][4]=&SK;
}

chessBoard::~chessBoard() {
for(int i=0;i<=7;++i)
    delete[] Field[i];
delete[] Field;

}

bool chessBoard::ifMovePutsKingInDanger(Piece* P, int tox, int toy) {
    Piece*** temp;
    temp = new Piece **[8];
   for(int i=0;i<=7;++i)
       temp[i] = new Piece*[8];

   int x = P->getX(), y = P->getY();

    Piece* tot=0;
    intpair oldPosTot;

    for(int i=0; i<=7;++i)
        for (int j=0;j<=7;++j)
            temp[i][j] = Field[i][j];

    if (temp[tox][toy]!=0) {
        tot = temp[tox][toy];
        oldPosTot = intpair(tot->getX(),tot->getY());
        tot->setX(-1);tot->setY(-1);
        temp[tox][toy] = 0;
    }
    else if (P->who == "Bauer" && toy != P->getY()) {
        tot = temp[P->getX()][toy];
        oldPosTot = intpair(tot->getX(),tot->getY());
        tot->setX(-1);tot->setY(-1);
        temp[P->getX()][toy] = 0;
    }
    temp[P->getX()][P->getY()] = 0;
    temp[tox][toy] = P;
    P->setX(tox);P->setY(toy);

    if (P->getColour()==Piece::W) {
        int Kx,Ky;
        if (P->who == "Koenig") {
            Kx=tox;Ky=toy;
        } else {
            Kx=WK.getX();Ky=WK.getY();
        }
        for (auto i : blackCrew) {
            if ( intpair(i->getX(),i->getY()) == intpair(-1,-1) ) continue;
            std::vector<intpair> v = i->possibleMoves(temp);
            auto result = std::find(v.begin(),v.end(),intpair(Kx,Ky));

            if (result!=v.end())  {
                if(tot!=0){tot->setX(oldPosTot.first);tot->setY(oldPosTot.second);}
                P->setX(x);P->setY(y);
                for(int i=0;i<=7;++i)
                    delete[] temp[i];
                delete[] temp;
                return true; }
        }
    } else if (P->getColour()==Piece::S) {
        int Kx,Ky;
        if (P->who == "Koenig") {
            Kx=tox;Ky=toy;
        } else {
            Kx=SK.getX();Ky=SK.getY();
        }
        for (auto i : whiteCrew) {
            if ( intpair(i->getX(),i->getY()) == intpair(-1,-1) ) continue;
            std::vector<intpair> v = i->possibleMoves(temp);
            auto result = std::find(v.begin(),v.end(),intpair(Kx,Ky));
            if (result!=v.end()) {
                if(tot!=0) {tot->setX(oldPosTot.first);tot->setY(oldPosTot.second);}
                P->setX(x);P->setY(y);
                for(int i=0;i<=7;++i)
                    delete[] temp[i];
                delete[] temp;
                return true; }
        }
    }
    if(tot!=0) {tot->setX(oldPosTot.first);tot->setY(oldPosTot.second);}
    P->setX(x);P->setY(y);
    for(int i=0;i<=7;++i)
       delete[] temp[i];
    delete[] temp;
    return false;



}



intpair chessBoard::detectKurzeRochade(Piece* P) {
    if (P->who=="Koenig"){

        if(!(P->getHasMoved()) && Field[P->getX()][P->getY()+1]==0 && Field[P->getX()][P->getY()+2]==0 && Field[P->getX()][P->getY()+3]!=0 && Field[P->getX()][P->getY()+3]->who=="Turm"
                && !(Field[P->getX()][P->getY()+3]->getHasMoved()) ) {
            std::vector<Piece*> crew;
            if (P->getColour()==Piece::W) crew = blackCrew; else crew = whiteCrew;
            bool roch=true;
            for (auto i : crew) {
               std::vector<intpair> p = i->possibleMoves(Field);
               if (std::find(p.begin(),p.end(),intpair(P->getX(),P->getY()))!=p.end() ||
                   std::find(p.begin(),p.end(),intpair(P->getX(),P->getY()+1))!=p.end() ||
                   std::find(p.begin(),p.end(),intpair(P->getX(),P->getY()+2))!=p.end() )
               {roch = false;break;}
               }
            if (roch==true) return intpair(P->getX(),P->getY()+2); else return intpair (-1,-1);
        }
}
    return intpair(-1,-1);

}

intpair chessBoard::detectLangeRochade(Piece* P) {
    if (P->who=="Koenig"){
    if(!(P->getHasMoved()) && Field[P->getX()][P->getY()-1]==0 && Field[P->getX()][P->getY()-2]==0 && Field[P->getX()][P->getY()-3]==0 &&
                    Field[P->getX()][P->getY()-4]!=0 &&  Field[P->getX()][P->getY()-4]->who=="Turm" && !(Field[P->getX()][P->getY()-4]->getHasMoved()) )
    {
                  std::vector<Piece*> crew;
                  if (P->getColour()==Piece::W) crew = blackCrew; else crew = whiteCrew;
                  bool roch=true;
                  for (auto i : crew) {
                     std::vector<intpair> p = i->possibleMoves(Field);
                     if (std::find(p.begin(),p.end(),intpair(P->getX(),P->getY()))!=p.end() ||
                         std::find(p.begin(),p.end(),intpair(P->getX(),P->getY()-1))!=p.end() ||
                         std::find(p.begin(),p.end(),intpair(P->getX(),P->getY()-2))!=p.end() )
                     {roch = false;break;}
                     }
                  if (roch==true) return intpair(P->getX(),P->getY()-2); else return intpair(-1,-1);
              }
    }
    return intpair(-1,-1);

}



bool chessBoard::move(Piece* P, int tox, int toy) {

    bool clear = true;
    intpair initpos=intpair(P->getX(),P->getY());
    Piece* tod = Field[tox][toy];

    std::vector<intpair> v=P->possibleMoves(Field);

    //enpassant
    if (std::find(enpassantcrew.begin(),enpassantcrew.end(),P)!=enpassantcrew.end())
        v.push_back(enpassant);

    //Rochade
   if ( detectKurzeRochade(P)!= intpair(-1,-1) ) v.push_back(detectKurzeRochade(P));

   if ( detectLangeRochade(P)!= intpair(-1,-1) ) v.push_back(detectLangeRochade(P));

//ende Rochade



    auto result=std::find(v.begin(),v.end(),intpair(tox,toy));
    if (result==v.end()) return false;

    //Rochade
    if (P->who=="Koenig" && inRange(toy-1,toy+1) && toy==P->getY()+2) {
        Field[tox][toy] = P;
        Field[P->getX()][P->getY()]=0;
        P->setX(tox);
        P->setY(toy);
        Field[tox][toy-1]=Field[tox][toy+1];
        Field[tox][toy+1]=0;
        Field[tox][toy-1]->setX(tox);
        Field[tox][toy-1]->setY(toy-1);

        enpassantcrew.clear();
        P->itHasMoved();
        return true;
    }
    if (P->who=="Koenig" && inRange(toy+1,toy-2) && toy==P->getY()-2) {
        Field[tox][toy] = P;
        Field[P->getX()][P->getY()]=0;
        P->setX(tox);
        P->setY(toy);
        Field[tox][toy+1]=Field[tox][toy-2];
        Field[tox][toy-2]=0;
        Field[tox][toy+1]->setX(tox);
        Field[tox][toy+1]->setY(toy+1);

        enpassantcrew.clear();
        P->itHasMoved();
        return true;
    }



    //Bauer schlaegt enpassant
    if(P->who=="Bauer" && toy!=P->getY() && Field[tox][toy]==0 && tox !=0 && toy != 7 ){
        tod = Field[P->getX()][toy];

        if (tod->getColour()==Piece::W) {
            auto i = std::find(whiteCrew.begin(),whiteCrew.end(),tod);
            whiteCrew.erase(i);
        } else if (tod->getColour()==Piece::S) {
            auto i = std::find(blackCrew.begin(),blackCrew.end(),tod);
            blackCrew.erase(i);
        }
        tod->setX(-1);tod->setY(-1);
        Field[P->getX()][toy]=0;

        Field[P->getX()][P->getY()]=0;
        Field[tox][toy]=P;
        P->setX(tox);P->setY(toy);

        if ((P->getColour()==Piece::W && !isKingSafe(&WK)) || (P->getColour()==Piece::S && !isKingSafe(&SK))) {
            Field[initpos.first][initpos.second]=P;
            P->setX(initpos.first);
            P->setY(initpos.second);
            Field[P->getX()][toy]=tod;

            if (tod->getColour()==Piece::W)
                whiteCrew.push_back(tod);
            else
                blackCrew.push_back(tod);
            tod->setX(P->getX());
            tod->setY(toy);

            return false;
        }

        enpassantcrew.clear();
        return true;



    }



    //Bauer wird transformiert
    if (P->who=="Bauer" && ( tox==0 || tox==7 )) {
        //can change later!!!!!!!
      /*  std::string s;
        std::cout << "Zu welcher Figur wollen Sie Ihren Bauer umwandeln?" << std::flush;
        std::cin>>s; */

        //transformBauer(P,tox,toy,"Dame");

        enpassantcrew.clear();
        return true;

    }
    //Bauer mit Doppelschritt
    if(P->who=="Bauer" && (tox - (P->getX()) ==2 || tox - (P->getX()) ==-2) ) {
        //gegenseitiger Bauer kann dann enpassant schlagen
        if (inRange(toy+1) && Field[tox][toy+1]!=0 && Field[tox][toy+1]->who=="Bauer" && Field[tox][toy+1]->getColour()!=P->getColour() ){
            enpassantcrew.push_back(Field[tox][toy+1]);
            enpassant = intpair((tox+P->getX())/2,toy);
            clear = false;}
        if (inRange(toy-1) && Field[tox][toy-1]!=0 && Field[tox][toy-1]->who=="Bauer" && Field[tox][toy-1]->getColour()!=P->getColour() ){
            enpassantcrew.push_back(Field[tox][toy-1]);
            enpassant = intpair((tox+P->getX())/2,toy);
            clear = false;}
    }


    //wieder normal
    //Zielfeld besetzt
    if (Field[tox][toy]!=0){
        if (Field[tox][toy]->getColour()==Piece::W) {
            auto i = std::find(whiteCrew.begin(),whiteCrew.end(),Field[tox][toy]);
            whiteCrew.erase(i);
          //  dead.push_back(Field[tox][toy]);
        } else if (Field[tox][toy]->getColour()==Piece::S) {
            auto i = std::find(blackCrew.begin(),blackCrew.end(),Field[tox][toy]);
            blackCrew.erase(i);
           // dead.push_back(Field[tox][toy]);
        }
        Field[tox][toy]->setX(-1);
        Field[tox][toy]->setY(-1);
    }
    Field[P->getX()][P->getY()]=0;
    Field[tox][toy]=P;
    P->setX(tox);P->setY(toy);

    if ((P->getColour()==Piece::W && !isKingSafe(&WK)) || (P->getColour()==Piece::S && !isKingSafe(&SK))) {
        Field[initpos.first][initpos.second]=P;
        P->setX(initpos.first);
        P->setY(initpos.second);
        Field[tox][toy]=tod;
        if (tod!=0){
            if (tod->getColour()==Piece::W)
                whiteCrew.push_back(tod);
            else
                blackCrew.push_back(tod);
            tod->setX(tox);
            tod->setY(toy);
        }
        return false;
    }





    P->itHasMoved();
    if (clear) enpassantcrew.clear();
    return true;
}



void chessBoard::transformBauer(Piece* P, int tox, int toy, std::string s) {
    if(s == "Dame")
        Field[tox][toy]=new Dame(tox,toy,P->getColour());
    else if(s == "Turm")
        Field[tox][toy]=new Turm(tox,toy,P->getColour());
    else if(s == "Springer")
        Field[tox][toy]=new Springer(tox,toy,P->getColour());
    else if(s == "Laeufer")
        Field[tox][toy]=new Laeufer(tox,toy,P->getColour());

      // Field[tox][toy]->setColour(P->getColour());
    // ....
    if (Field[tox][toy]->getColour()==Piece::W) {
        auto i = std::find(whiteCrew.begin(),whiteCrew.end(),P);
        whiteCrew.erase(i);
        whiteCrew.push_back(Field[tox][toy]);
    } else if (Field[tox][toy]->getColour()==Piece::S) {
        auto i = std::find(blackCrew.begin(),blackCrew.end(),P);
        blackCrew.erase(i);
        blackCrew.push_back(Field[tox][toy]);
    }

    //Field[tox][toy]->setX(tox);Field[tox][toy]->setY(toy);
    Field[P->getX()][P->getY()]=0;
    P->setX(-1);P->setY(-1);
}


bool chessBoard::isKingSafe (Piece* P) {
    if (P->getColour()==Piece::W) {
        for (auto i : blackCrew) {
            std::vector<intpair> v = i->possibleMoves(Field);
            auto result = std::find(v.begin(),v.end(),intpair(P->getX(),P->getY()));
            if (result!=v.end()) return false;
        }
    } else if (P->getColour()==Piece::S) {
        for (auto i : whiteCrew) {
            std::vector<intpair> v = i->possibleMoves(Field);
            auto result = std::find(v.begin(),v.end(),intpair(P->getX(),P->getY()));
            if (result!=v.end()) return false;
        }
    }
    return true;
}







