#ifndef PLAYERWHITEWINS_H
#define PLAYERWHITEWINS_H

#include <QDialog>

namespace Ui {
class PlayerWhiteWins;
}

class PlayerWhiteWins : public QDialog
{
    Q_OBJECT
    /**
     * @brief diese klasse beendet das Spiel mit einem Gif
     */

public:
    explicit PlayerWhiteWins(QWidget *parent = 0);
    ~PlayerWhiteWins();

private slots:
    void on_label_linkActivated(const QString &link);

    void on_Label_linkActivated(const QString &link);

private:
    Ui::PlayerWhiteWins *ui;
};

#endif // PLAYERWHITEWINS_H
