#ifndef USERDATA_H
#define USERDATA_H

#include <QDialog>
#include"widget.h"
namespace Ui {
class userdata;
}
/**
 * @brief Diese klasse erlaubt den User, seine daten abzugeben damit sie dann spater uebermittelt werden koennten zu dem Gegner/ Ein data submittion
 * ohne alle Kasen auszufuellen ist nicht moeglich

*/
class userdata : public QDialog
{
    Q_OBJECT


public:
    explicit userdata(QWidget *parent = 0);
    ~userdata();

private slots:
    void on_pushButton_clicked();

private:
    Ui::userdata *ui;
Widget window0;

};

#endif // USERDATA_H
