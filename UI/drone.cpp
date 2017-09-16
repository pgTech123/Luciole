#include "drone.h"
#include "ui_drone.h"

Drone::Drone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Drone)
{
    ui->setupUi(this);

    m_voltageCell1 = new ValueElement(this, "Voltage Cell 1");
    m_voltageCell2 = new ValueElement(this, "Voltage Cell 2");
    m_voltageCell3 = new ValueElement(this, "Voltage Cell 3");
    m_voltageCell4 = new ValueElement(this, "Voltage Cell 4");

    m_currentCell1 = new ValueElement(this, "Current Cell 1");
    m_currentCell2 = new ValueElement(this, "Current Cell 2");
    m_currentCell3 = new ValueElement(this, "Current Cell 3");
    m_currentCell4 = new ValueElement(this, "Current Cell 4");

    m_powerCell1 = new ValueElement(this, "Power Cell 1");
    m_powerCell2 = new ValueElement(this, "Power Cell 2");
    m_powerCell3 = new ValueElement(this, "Power Cell 3");
    m_powerCell4 = new ValueElement(this, "Power Cell 4");

    m_batVoltageCell1 = new ValueElement(this, "Battery Voltage Cell 1");
    m_batVoltageCell2 = new ValueElement(this, "Battery Voltage Cell 2");
    m_batVoltageCell3 = new ValueElement(this, "Battery Voltage Cell 3");
    m_batCurrent = new ValueElement(this, "Battery Current");

    ui->verticalLayout->addWidget(m_voltageCell1);
    ui->verticalLayout->addWidget(m_currentCell1);
    ui->verticalLayout->addWidget(m_powerCell1);

    ui->verticalLayout->addWidget(m_voltageCell2);
    ui->verticalLayout->addWidget(m_currentCell2);
    ui->verticalLayout->addWidget(m_powerCell2);

    ui->verticalLayout->addWidget(m_voltageCell3);
    ui->verticalLayout->addWidget(m_currentCell3);
    ui->verticalLayout->addWidget(m_powerCell3);

    ui->verticalLayout->addWidget(m_voltageCell4);
    ui->verticalLayout->addWidget(m_currentCell4);
    ui->verticalLayout->addWidget(m_powerCell4);

   /* ui->verticalLayout->addWidget(m_batVoltageCell1);
    ui->verticalLayout->addWidget(m_batVoltageCell2);
    ui->verticalLayout->addWidget(m_batVoltageCell3);
    ui->verticalLayout->addWidget(m_batCurrent);
*/


    this->setLayout(ui->verticalLayoutMain);
    ui->verticalLayoutMain->addWidget(ui->scrollArea);
    ui->scrollAreaWidgetContents->setLayout(ui->verticalLayout);
}

Drone::~Drone()
{
    delete ui;
}
