#include "laser.h"
#include "ui_laser.h"

Laser::Laser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Laser)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout_2);
}

Laser::~Laser()
{
    delete ui;
}
