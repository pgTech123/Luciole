#include "battery.h"
#include "ui_battery.h"

Battery::Battery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battery)
{
    ui->setupUi(this);

    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_view->setScene(m_scene);
    this->setupScene();

    m_batVoltageGlobal = new ValueElement(this, "Battery Voltage Global");
    m_batVoltageCell1 = new ValueElement(this, "Battery Voltage Cell 1");
    m_batVoltageCell2 = new ValueElement(this, "Battery Voltage Cell 2");
    m_batVoltageCell3 = new ValueElement(this, "Battery Voltage Cell 3");
    m_batCurrent = new ValueElement(this, "Battery Current");
    m_batTemperature = new ValueElement(this, "Battery Temperature");

    ui->verticalLayout->addWidget(m_batVoltageGlobal);
    ui->verticalLayout->addWidget(m_batVoltageCell1);
    ui->verticalLayout->addWidget(m_batVoltageCell2);
    ui->verticalLayout->addWidget(m_batVoltageCell3);
    ui->verticalLayout->addWidget(m_batCurrent);
    ui->verticalLayout->addWidget(m_batTemperature);
    ui->verticalLayout->addWidget(m_view);

    this->setLayout(ui->verticalLayout);
}

Battery::~Battery()
{
    delete ui;
}

void Battery::error(int id, bool simulated)
{
    switch (id) {
    case BAT_TOT:
        m_batVoltageGlobal->triggerAlarm(simulated);
        break;
    case BAT_CELL1:
        m_batVoltageCell1->triggerAlarm(simulated);
        break;
    case BAT_CELL2:
        m_batVoltageCell2->triggerAlarm(simulated);
        break;
    case BAT_CELL3:
        m_batVoltageCell3->triggerAlarm(simulated);
        break;
    case BAT_CURRENT:
        m_batCurrent->triggerAlarm(simulated);
        break;
    case BAT_TEMPERATURE:
        m_batTemperature->triggerAlarm(simulated);
        break;
    default:
        break;
    }
}

void Battery::valueChanged(int id, float value, bool)
{
    switch (id) {
    case BAT_TOT:
        m_batVoltageGlobal->setValue(value);
        break;
    case BAT_CELL1:
        m_batVoltageCell1->setValue(value);
        break;
    case BAT_CELL2:
        m_batVoltageCell2->setValue(value);
        break;
    case BAT_CELL3:
        m_batVoltageCell3->setValue(value);
        break;
    case BAT_CURRENT:
        m_batCurrent->setValue(value);
        break;
    case BAT_TEMPERATURE:
        m_batTemperature->setValue(value);
        break;
    default:
        break;
    }
}

void Battery::setupScene()
{
    //TODO: Mettre le dessin anime que Carlos va faire :P
}
