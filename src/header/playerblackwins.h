#ifndef PLAYERBLACKWINS_H
#define PLAYERBLACKWINS_H

#include <QDialog>

namespace Ui {
class PlayerBlackWins;
}
/**
 * @brief diese klasse beendet das Spiel mit einem Gif
 */

class PlayerBlackWins : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerBlackWins(QWidget *parent = 0);
    ~PlayerBlackWins();

private:
    Ui::PlayerBlackWins *ui;
};

#endif // PLAYERBLACKWINS_H
