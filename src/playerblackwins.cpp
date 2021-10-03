#include "playerblackwins.h"
#include "ui_playerblackwins.h"
#include<QString>
#include<QLabel>
#include<QPixmap>
#include<QtWidgets>
#include<QtGui>

PlayerBlackWins::PlayerBlackWins(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerBlackWins)
{
    ui->setupUi(this);
    this->setWindowTitle("Check mate");
    QMovie *movie = new QMovie(":/giphy.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();
}

PlayerBlackWins::~PlayerBlackWins()
{
    delete ui;
}
