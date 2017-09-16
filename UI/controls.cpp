#include "controls.h"
#include "ui_controls.h"

Controls::Controls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controls)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);
}

Controls::~Controls()
{
    delete ui;
}
