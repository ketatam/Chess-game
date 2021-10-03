#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QDialog>
#include<widget.h>
#include"credits.h"
#include"userdata.h"
namespace Ui {
class Userinterface;
}
/**
 * @brief Diese klasse repraesentiert unseres main window/ Credits,Load game und play game window sind alle zu dem mainwindow gelinkt mit pushbuttons
 * und connects/ Das haben wir das background und ein logo fuer unsere spiel gestellt */
class Userinterface : public QDialog
{
    Q_OBJECT


public:
    explicit Userinterface(QWidget *parent = 0);
    ~Userinterface();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Userinterface *ui;
userdata window;
  //  Widget window0;
    credits window1;

};

#endif // USERINTERFACE_H
