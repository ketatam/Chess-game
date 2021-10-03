/**
  * @file piece.h Headerdatei für die Piece abstrakte Klasse
  *
  * @author Mohamed Amine Ketata
  *
  **/
#ifndef PIECE_H
#define PIECE_H
#include<utility>
#include<vector>
#include<string>
/**
 * @brief pair aus zwei Integern
 */
typedef std::pair<int,int> intpair;
/**
 * @brief Hilfsfunktion um zu überprüfen, ob die zu verwendenden Indizes im zulässigen Bereich [0,7) von der Fieldmatriz sind; kann auch nur für einen Parameter
 * aufgerufen wird
 * @param x : erster Parameter
 * @param y : zweiter optionaler Parameter
 * @return true, falls die Parameter im Bereich [0,7) sind, ansonsten false
 */
bool inRange(int x, int y=0);
/**
 * @brief The Piece class; abstrakte Klasse für die Grundstruktur aller Schachfiguren, von der alle Schachfiguen erben werden.
 */
class Piece
{
public:
    /**
     * @brief The Colour enum definiert die Farben, die eine Schachfigur annehmen kann
     */
    enum Colour {W,S};
    /**
     * @brief gibt an, um welche Figur es handelt
     */
    std::string who;
    /**
     * @brief Piece default Constructor
     */
    Piece();
    /**
     * @brief Piece Constructor : legt eine neue Schachfigur an, mit vorgegebenen Position und Farbe
     * @param x Zeile
     * @param y Spalte
     * @param c Farbe
     */
    Piece(int x,int y, Colour c);
    int getX() {return _X;};
    int getY() {return _Y;};
    void setX(int x) {_X=x;};
    void setY(int y) {_Y=y;};
    Colour getColour() {return _Col;};
    void setColour(Colour C){_Col = C;};
    /**
     * @brief bestimmt alle möglichen Züge, die die Schahfigur ausführen kann, erstmal aber ohne Betrachtung des Schachmattes
     * @return einen Vector, der die Positionen aller möglichen Züge enthält
     */
    virtual std::vector<intpair> possibleMoves (Piece*** )=0;
    /**
     * @brief wird aufgerufen, wenn die Schachfigur einen Zug erfolgreich ausgeführt hat. setzt die Variable hasMoved auf true.
     * wird insebesondere verwendet bei den Doppelschritten der Bauern und bei den Rochaden.
     */
    void itHasMoved() {if(!hasMoved) hasMoved=true;};
    bool getHasMoved(){return hasMoved;};
private:
    /// die Position der Schachfigur: Spalte und Zeile
    int _X,_Y;
    /**
      * @brief die Farbe der Schachfigur
      */
     Colour _Col;
     /**
     * @brief gibt an, ob die Schachfigur schon mindestens einen Zug ausgeführt hat
     */
    bool hasMoved = false;
};
#endif // PIECE_H
