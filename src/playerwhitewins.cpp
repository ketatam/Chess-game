#include "playerwhitewins.h"
#include "ui_playerwhitewins.h"
#include<QString>
#include<QLabel>
#include<QPixmap>
#include<QtWidgets>
#include<QtGui>

PlayerWhiteWins::PlayerWhiteWins(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerWhiteWins)
{
    ui->setupUi(this);
     this->setWindowTitle("Check mate");
    QMovie *movie = new QMovie(":/giphy.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
}

PlayerWhiteWins::~PlayerWhiteWins()
{
    delete ui;
}



