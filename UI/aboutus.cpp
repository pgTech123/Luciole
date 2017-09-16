/*********************************************************
 * AboutUs.cpp
 * Author: Pascal Gendron
 * Version:     0.1.0
 * *******************************************************/

#include "aboutus.h"
#include "ui_aboutus.h"

AboutUs::AboutUs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutUs)
{
    ui->setupUi(this);
    this->setFixedSize(380,220);
}

AboutUs::~AboutUs()
{
    delete ui;
}
