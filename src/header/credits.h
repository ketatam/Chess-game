

#ifndef CREDITS_H
#define CREDITS_H

#include <QDialog>

namespace Ui {
class credits;
}
/**
 * @Brief diese klasse gibt unsere Namen und die copyrights aus
 */
class credits : public QDialog
{
    Q_OBJECT

public:

    explicit credits(QWidget *parent = 0);
    ~credits();

private:
    Ui::credits *ui;
};

#endif // CREDITS_H
