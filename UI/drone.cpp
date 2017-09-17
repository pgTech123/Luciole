#include "drone.h"
#include "ui_drone.h"

Drone::Drone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Drone)
{
    ui->setupUi(this);

    m_voltageGlobal = new ValueElement(this, "Voltage Global");

    m_temperatureCell1 = new ValueElement(this, "Temperature Cell 1");
    m_temperatureCell2 = new ValueElement(this, "Temperature Cell 2");
    m_temperatureCell3 = new ValueElement(this, "Temperature Cell 3");
    m_temperatureCell4 = new ValueElement(this, "Temperature Cell 4");

    m_currentCell1 = new ValueElement(this, "Current Cell 1");
    m_currentCell2 = new ValueElement(this, "Current Cell 2");
    m_currentCell3 = new ValueElement(this, "Current Cell 3");
    m_currentCell4 = new ValueElement(this, "Current Cell 4");

    m_powerCell1 = new ValueElement(this, "Power Cell 1");
    m_powerCell2 = new ValueElement(this, "Power Cell 2");
    m_powerCell3 = new ValueElement(this, "Power Cell 3");
    m_powerCell4 = new ValueElement(this, "Power Cell 4");

    ui->verticalLayout->addWidget(m_voltageGlobal);

    ui->verticalLayout->addWidget(m_temperatureCell1);
    ui->verticalLayout->addWidget(m_currentCell1);
    ui->verticalLayout->addWidget(m_powerCell1);

    ui->verticalLayout->addWidget(m_temperatureCell2);
    ui->verticalLayout->addWidget(m_currentCell2);
    ui->verticalLayout->addWidget(m_powerCell2);

    ui->verticalLayout->addWidget(m_temperatureCell3);
    ui->verticalLayout->addWidget(m_currentCell3);
    ui->verticalLayout->addWidget(m_powerCell3);

    ui->verticalLayout->addWidget(m_temperatureCell4);
    ui->verticalLayout->addWidget(m_currentCell4);
    ui->verticalLayout->addWidget(m_powerCell4);

    this->setLayout(ui->verticalLayoutMain);
    ui->verticalLayoutMain->addWidget(ui->scrollArea);
    ui->scrollAreaWidgetContents->setLayout(ui->verticalLayout);
}

Drone::~Drone()
{
    delete ui;
}

void Drone::error(int id, bool simulated)
{
    switch (id) {
    case TEMPERATURE_CELL1:
        m_temperatureCell1->triggerAlarm(simulated);
        break;
    case TEMPERATURE_CELL2:
        m_temperatureCell2->triggerAlarm(simulated);
        break;
    case TEMPERATURE_CELL3:
        m_temperatureCell3->triggerAlarm(simulated);
        break;
    case TEMPERATURE_CELL4:
        m_temperatureCell4->triggerAlarm(simulated);
        break;
    case CURRENT_CELL1:
        m_currentCell1->triggerAlarm(simulated);
        break;
    case CURRENT_CELL2:
        m_currentCell2->triggerAlarm(simulated);
        break;
    case CURRENT_CELL3:
        m_currentCell3->triggerAlarm(simulated);
        break;
    case CURRENT_CELL4:
        m_currentCell4->triggerAlarm(simulated);
        break;
    case VOLTAGE_GLOBAL:
        m_voltageGlobal->triggerAlarm(simulated);
        break;
    default:
        break;
    }
}

void Drone::valueChanged(int id, float value, bool simulated)
{
    switch (id) {
    case TEMPERATURE_CELL1:
        m_temperatureCell1->setValue(value);
        break;
    case TEMPERATURE_CELL2:
        m_temperatureCell2->setValue(value);
        break;
    case TEMPERATURE_CELL3:
        m_temperatureCell3->setValue(value);
        break;
    case TEMPERATURE_CELL4:
        m_temperatureCell4->setValue(value);
        break;
    case CURRENT_CELL1:
        m_currentCell1->setValue(value);
        m_powerCell1->setValue(value * m_voltageGlobal->getValue());
        break;
    case CURRENT_CELL2:
        m_currentCell2->setValue(value);
        m_powerCell2->setValue(value * m_voltageGlobal->getValue());
        break;
    case CURRENT_CELL3:
        m_currentCell3->setValue(value);
        m_powerCell3->setValue(value * m_voltageGlobal->getValue());
        break;
    case CURRENT_CELL4:
        m_currentCell4->setValue(value);
        m_powerCell4->setValue(value * m_voltageGlobal->getValue());
        break;
    case VOLTAGE_GLOBAL:
        m_voltageGlobal->setValue(value);
        m_powerCell1->setValue(value * m_currentCell1->getValue());
        m_powerCell2->setValue(value * m_currentCell2->getValue());
        m_powerCell3->setValue(value * m_currentCell3->getValue());
        m_powerCell4->setValue(value * m_currentCell4->getValue());
        break;
    default:
        break;
    }
}
