/**
  * @file chessboard.h Headerdatei für die Chessboard Klasse
  *
  * @author Mohamed Amine Ketata
  *
  **/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include<algorithm>
#include"bauer.h"
#include"springer.h"
#include"koenig.h"
#include"turm.h"
#include"laeufer.h"
#include"dame.h"
#include<iostream>
/**
 * @brief The chessBoard class beiinhaltet den Schachbrett und kontrolliert alle Züge
 */
class chessBoard
{
public:
    /**
     * @brief chessBoard Constructor
     *
     * erzeugt das Schachbrett und alle Schachfiguren
     */
    chessBoard();
    ~chessBoard();
    /**
     * @brief Field das Schachbrett : Matrix aus Zeigern auf alle Schachfiguren
     */
    Piece*** Field;

    /**
     * @brief überpruft ob Zug möglich ist und führt gegebenfalls die dazugehörigen Veränderungen auf dem Schachbrett
     * @param P : die zu bewegende Schachfigur
     * @param tox : Zielzeile
     * @param toy : Zielspalte
     * @return true falls der Zug erfolgreich war, ansonsten false
     */
    bool move(Piece* P, int tox, int toy);
    /**
     * @brief wird aufgerufen wenn ein Bauer die letzte Reihe erreicht und wird dann zu einer ausgewählten Figur umgewandelt
     * @param P : der zu transformierende Bauer
     * @param tox : Zielzeile
     * @param toy : Zielspalte
     * @param s : gibt an, zu welcher Figur umgewandelt wird
     */

    void transformBauer(Piece* P, int tox, int toy,std::string s);
    /**
     * @brief Hilfsfunktion für die Funktion ifMovePutsKingInDanger; überprüft ob der König gerade in Sicherheit ist
     * @param P : der König
     * @return true, falls derKönig sicher ist, ansonsten false
     */
    bool isKingSafe (Piece* P);
    /**
     * @brief überprüft ob der Zug den zugehörigen König in Gefahr bringt, falls dieser Zug ausgeführt wird;
     * @param P : die zu bewegende Schachfigur
     * @param tox : Zielzeile
     * @param toy : Zielspalte
     * @return true, falls der Zug den zugehörigen König in Gefahr bringt, ansonsten false
     */
    bool ifMovePutsKingInDanger(Piece* P, int tox, int toy);
    /**
     * @brief gibt an, ob der Zug eine kurze Rochade ist
     * @param P : die zu bewegende Schachfigur
     * @return die Position, an die der König springen wird
     */
    intpair detectKurzeRochade(Piece* P);
    /**
     * @brief gibt an, ob der Zug eine lange Rochade ist
     * @param P : die zu bewegende Schachfigur
     * @return die Position, an die der König springen wird
     */
    intpair detectLangeRochade(Piece* P);
    /**
     * @brief Vector aus Zeigern auf die Bauern, die gerade en passant schlagen können
     */

    std::vector<Piece*> enpassantcrew;
    /**
     * @brief enthält die Position des Bauers, der im nächsten Zug en passant geschlagen werden kann
     */
    intpair enpassant=intpair(0,0);
private:
    /// alle Anfangsschachfiguren
    Bauer WB1=Bauer(6,0,Piece::W),WB2=Bauer(6,1,Piece::W),WB3=Bauer(6,2,Piece::W),WB4=Bauer(6,3,Piece::W),
          WB5=Bauer(6,4,Piece::W),WB6=Bauer(6,5,Piece::W),WB7=Bauer(6,6,Piece::W),WB8=Bauer(6,7,Piece::W),
          SB1=Bauer(1,0,Piece::S),SB2=Bauer(1,1,Piece::S),SB3=Bauer(1,2,Piece::S),SB4=Bauer(1,3,Piece::S),
          SB5=Bauer(1,4,Piece::S),SB6=Bauer(1,5,Piece::S),SB7=Bauer(1,6,Piece::S),SB8=Bauer(1,7,Piece::S);

    Springer WS1=Springer(7,1,Piece::W),WS2=Springer(7,6,Piece::W),
             SS1=Springer(0,1,Piece::S),SS2=Springer(0,6,Piece::S);
    Turm WT1=Turm(7,0,Piece::W),WT2=Turm(7,7,Piece::W),
             ST1=Turm(0,0,Piece::S),ST2=Turm(0,7,Piece::S);
    Laeufer WL1=Laeufer(7,2,Piece::W),WL2=Laeufer(7,5,Piece::W),
            SL1=Laeufer(0,2,Piece::S),SL2=Laeufer(0,5,Piece::S);
    Dame WD=Dame(7,3,Piece::W), SD=Dame(0,3,Piece::S);
    Koenig WK=Koenig(7,4,Piece::W),SK=Koenig(0,4,Piece::S);
public:
    /**
      * @brief Vector aus Zeigern auf alle noch im Spiel befindenden weißen Schachfiguren
      * */
    std::vector<Piece*> whiteCrew={&WB1,&WB2,&WB3,&WB4,&WB5,&WB6,&WB7,&WB8,&WS1,&WS2,&WT1,&WT2,&WL1,&WL2,&WD,&WK};
    /**
     * @brief Vector aus Zeigern auf alle noch im Spiel befindenden weißen Schachfiguren
     * */

    std::vector<Piece*> blackCrew={&SB1,&SB2,&SB3,&SB4,&SB5,&SB6,&SB7,&SB8,&SS1,&SS2,&ST1,&ST2,&SL1,&SL2,&SD,&SK};
};

#endif // CHESSBOARD_H
