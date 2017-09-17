#include "laser.h"
#include "ui_laser.h"

Laser::Laser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Laser)
{
    ui->setupUi(this);

    m_TemperatureLaser1 = new ValueElement(this, "Laser 1", true);
    m_TemperatureLaser2 = new ValueElement(this, "Laser 2", true);
    m_TemperatureLaser3 = new ValueElement(this, "Laser 3", true);
    m_TemperatureLaser4 = new ValueElement(this, "Laser 4", true);

    ui->horizontalLayout->addWidget(m_TemperatureLaser1);
    ui->horizontalLayout->addWidget(m_TemperatureLaser2);
    ui->horizontalLayout->addWidget(m_TemperatureLaser3);
    ui->horizontalLayout->addWidget(m_TemperatureLaser4);

    this->setLayout(ui->horizontalLayout);
}

Laser::~Laser()
{
    delete ui;
}

void Laser::error(int id, bool simulated)
{
    switch (id) {
    case TEMPERATURE_LASER1:
        m_TemperatureLaser1->triggerAlarm(simulated);
        break;
    case TEMPERATURE_LASER2:
        m_TemperatureLaser2->triggerAlarm(simulated);
        break;
    case TEMPERATURE_LASER3:
        m_TemperatureLaser3->triggerAlarm(simulated);
        break;
    case TEMPERATURE_LASER4:
        m_TemperatureLaser4->triggerAlarm(simulated);
        break;
    default:
        break;
    }
}

void Laser::valueChanged(int id, float value, bool)
{
    switch (id) {
    case TEMPERATURE_LASER1:
        m_TemperatureLaser1->setValue(value);
        break;
    case TEMPERATURE_LASER2:
        m_TemperatureLaser2->setValue(value);
        break;
    case TEMPERATURE_LASER3:
        m_TemperatureLaser3->setValue(value);
        break;
    case TEMPERATURE_LASER4:
        m_TemperatureLaser4->setValue(value);
        break;
    default:
        break;
    }
}
