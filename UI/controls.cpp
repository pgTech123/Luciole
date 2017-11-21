#include "controls.h"
#include "ui_controls.h"

Controls::Controls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controls)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);

    connect(ui->pushButtonLock, SIGNAL(clicked(bool)), this, SLOT(runMode(bool)));
}

Controls::~Controls()
{
    delete ui;
}

void Controls::error(int, bool)
{
    if(!ui->pushButtonEmergencyStop->isEnabled()){
        unlock(true);
    }
}

void Controls::valueChanged(int id, float value, bool)
{
    switch (id) {
    case POWER_SUPPLY_VOLTAGE:
        ui->lcdNumberVoltage->display(value);
        break;
    default:
        break;
    }
}

void Controls::statusUpdate(unsigned char status)
{
    ui->modeLabel->setText("Mode: " + QString::number(status));
}

void Controls::unlock(bool)
{
    ui->pushButtonLock->setText("Lock");
    ui->pushButtonEmergencyStop->setEnabled(true);
    disconnect(ui->pushButtonLock, SIGNAL(clicked(bool)), this, SLOT(unlock(bool)));
    connect(ui->pushButtonLock, SIGNAL(clicked(bool)), this, SLOT(lock(bool)));
}

void Controls::lock(bool)
{
    ui->pushButtonLock->setText("Unlock");
    ui->pushButtonEmergencyStop->setDisabled(true);
    disconnect(ui->pushButtonLock, SIGNAL(clicked(bool)), this, SLOT(lock(bool)));
    connect(ui->pushButtonLock, SIGNAL(clicked(bool)), this, SLOT(unlock(bool)));
}

void Controls::runMode(bool)
{
    QByteArray data = "R";
    emit emergency(data);
    lock(true);
}

void Controls::on_pushButtonEmergencyStop_clicked(bool)
{
    QByteArray data = "E";
    emit emergency(data);
}

void Controls::on_pushButtonChg_clicked(bool)
{
    QByteArray data = "2";
    emit emergency(data);
}

void Controls::on_pushButtonDsg_clicked(bool)
{
    QByteArray data = "3";
    emit emergency(data);
}

void Controls::on_pushButtonChgDsg_clicked(bool)
{
    QByteArray data = "4";
    emit emergency(data);
}

void Controls::on_pushButtonReset_clicked(bool)
{
    QByteArray data = "5";
    emit emergency(data);
}

void Controls::on_pushButtonStb_clicked(bool)
{
    QByteArray data = "1";
    emit emergency(data);
}

void Controls::on_pushButtonRstEmergency_clicked(bool)
{
    QByteArray data = "S";
    emit emergency(data);
}

void Controls::on_pushButtonUp_clicked(bool)
{
    QByteArray data = "+";
    emit emergency(data);
}

void Controls::on_pushButtonDown_clicked(bool)
{
    QByteArray data = "-";
    emit emergency(data);
}
