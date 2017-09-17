#include "systems.h"
#include "ui_systems.h"

Systems::Systems(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Systems)
{
    ui->setupUi(this);
}

Systems::~Systems()
{
    delete ui;
}

void Systems::error(int id, bool simulated)
{

}

void Systems::valueChanged(int id, float value, bool simulated)
{

}
