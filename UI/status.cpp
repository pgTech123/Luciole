#include "status.h"
#include "ui_status.h"

Status::Status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Status)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);
    m_disconnectionTimeout = new QTimer();
    m_disconnectionTimeout->start(DISCONNECTION_TIMEOUT);
    connect(m_disconnectionTimeout, SIGNAL(timeout()), this, SLOT(rs232Disconnected()));
}

Status::~Status()
{
    delete ui;
    delete m_disconnectionTimeout;
}

void Status::error(int, bool)
{

}

void Status::valueChanged(int, float, bool)
{

}

void Status::statusUpdate(unsigned char status)
{
    // Restart the timer since we received some data
    m_disconnectionTimeout->start(DISCONNECTION_TIMEOUT);

    ui->labelRs232->setText("Connected");

    if ( status & 0x01) {
        ui->labelStartup->setText("Run");
    } else {
        ui->labelStartup->setText("Startup");
    }
    if ( status & 0x02) {
        ui->labelEmergency->setText("Houston, we have a problem...");
    } else {
        ui->labelEmergency->setText("No Problem");
    }
    if ( status & 0x04) {
        ui->labelRf->setText("Connected");
    } else {
        ui->labelRf->setText("Not Connected");
    }
    if ( status & 0x08) {
        ui->labelPowerSupply->setText("Connected");
    } else {
        ui->labelPowerSupply->setText("Not Connected");
    }
    if ( status & 0x10) {
        ui->labelControl->setText("Enabled");
    } else {
        ui->labelControl->setText("Disabled");
    }
}

// FIXME: Not tested
void Status::rs232Disconnected()
{
    ui->labelRs232->setText("Disconnected");
    ui->labelStartup->setText("N/A");
    ui->labelEmergency->setText("N/A");
    ui->labelRf->setText("N/A");
    ui->labelPowerSupply->setText("N/A");
    ui->labelControl->setText("N/A");
}
