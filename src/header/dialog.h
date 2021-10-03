/**
  * @file dialog.h Headerdatei für die Dialog Klasse
  *
  * @author Mohamed Amine Ketata
  *
  **/
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}
/**
 * @brief The Dialog class wird angezeigt, wenn ein Bauer die letzte gegnerische Reihe erreicht hat, um auszuwählen, zu welcher Figur umgewandelt werden soll
 */
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
signals:
    /**
     * @brief wird gesendet, wenn auf den Queenbutton geclickt wird
     */
    void QueenSignal();
    /**
     * @brief wird gesendet, wenn auf den Turmbutton geclickt wird
     */
    void TurmSignal();
    /**
     * @brief wird gesendet, wenn auf den Springerbutton geclickt wird
     */
    void SpringerSignal();
    /**
     * @brief wird gesendet, wenn auf den Läuferbutton geclickt wird
     */
    void LaueferSignal();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
