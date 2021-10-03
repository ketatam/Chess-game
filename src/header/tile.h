#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>
/**
 * @brief externe Variable, um zu wissen, ob es sich um den ersten oder um den zweiten Click handelt
 */
extern int count;
/**
 * @brief The Tile class beschreibt ein einziges Square aus dem Schachbrett als Label
 */
class Tile: public QLabel
{
public:
    int tileColor,piece,pieceColor,row,col,tileNum;
    char pieceName;

    static int count_init;

    Tile(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) { count_init++;};
    Tile(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){count_init++;};
    /**
     * @brief wird aufgerufen, wenn auf einem Square geclickt wurde. Dann wird eine Hilfsfunktion validate aufgerufen
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief zeigt die entsprechende Figur an oder nichts, wenn der Square leer ist
     * @param elem: die auf diesem Square befindende Figur
     */
    void display(char elem);
    /**
     * @brief zeigt die Farbe des Squares
     */
    void tileDisplay();
    /**
     * @brief überprüft, ob der auszuführende Zug ein enpassantSchlag ist
     * @param c gibt an, um welche Figur es sich handelt
     * @param y Startspalte
     * @param tox Zielzeile
     * @param toy Zielspalte
     * @return true, falls es tatsäschlich um einen enpassantschlag handelt, ansonsten false
     */
    bool detectEnPassant (char c,  int y, int tox, int toy);
    /**
     * @brief überprüft, ob der auszuführende Zug ein Kurze Rochade ist
     * @param c gibt an, um welche Figur es sich handelt
     * @param y Startspalte
     * @param toy Zielsaplte
     * @return true, falls es tatsäschlich um einen enpassantschlag handelt, ansonsten false
     */
    bool detectKleineRochade (char c,  int y,  int toy);
    /**
     * @brief überprüft, ob der auszuführende Zug ein lange Rochade ist
     * @param c gibt an, um welche Figur es sich handelt
     * @param y Startspalte
     * @param toy Zielspalte
     * @return
     */
    bool detectGrosseRochade (char c,  int y,  int toy);
};
#endif // TILE_H
