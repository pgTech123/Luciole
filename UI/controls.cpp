#include "controls.h"
#include "ui_controls.h"

Controls::Controls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controls)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);

    connect(ui->pushButtonLock, SIGNAL(clicked(bool)), this, SLOT(unlock(bool)));
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

void Controls::valueChanged(int id, float value, bool simulated)
{
    // Unused
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

void Controls::on_pushButtonEmergencyStop_clicked(bool)
{
    //TODO: Emergency Stop sequence here
}
