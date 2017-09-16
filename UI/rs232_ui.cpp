#include "rs232_ui.h"
#include "ui_rs232_ui.h"

Rs232_ui::Rs232_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rs232_ui)
{
    ui->setupUi(this);
}

Rs232_ui::~Rs232_ui()
{
    delete ui;
}
