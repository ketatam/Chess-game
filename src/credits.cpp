#include "credits.h"
#include "ui_credits.h"

credits::credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credits)
{
    ui->setupUi(this);
    this->setWindowTitle("Credits window");
}

credits::~credits()
{
    delete ui;
}
