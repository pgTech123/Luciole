#include "supplycontrol.h"
#include "ui_supplycontrol.h"

SupplyControl::SupplyControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupplyControl)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);

    m_voltageWantedValue = 0;
    m_currentWantedValue = 0;
}

SupplyControl::~SupplyControl()
{
    delete ui;
}

void SupplyControl::error(int id, bool simulated)
{
    switch (id) {
    default:
        break;
    }
}

void SupplyControl::valueChanged(int id, float value, bool)
{
    switch (id) {
    case POWER_SUPPLY_VOLTAGE_MEASURED:
        ui->lcdNumberRealVoltage->display(value);
        break;
    case POWER_SUPPLY_CURRENT_MEASURED:
        ui->lcdNumberRealCurrent->display(value);
        break;
    case POWER_SUPPLY_VOLTAGE:
        ui->lcdNumberVoltage->display(value);
        break;
    case POWER_SUPPLY_CURRENT:
        ui->lcdNumberCurrent->display(value);
        break;
    default:
        break;
    }
}


void SupplyControl::on_pushButtonVoltageUp_clicked(bool)
{
    m_voltageWantedValue += ui->doubleSpinBoxVoltageStep->value();
    if (m_voltageWantedValue > MAX_VOLTAGE){
        m_voltageWantedValue = MAX_VOLTAGE;
    }
    ui->lcdNumberVoltage->display(m_voltageWantedValue);
    QString cmd = "Volt: " + QString::number(m_voltageWantedValue);
    QByteArray data = cmd.toLocal8Bit();

    emit emergency(data);
}

void SupplyControl::on_pushButtonVoltageDown_clicked(bool)
{
    m_voltageWantedValue -= ui->doubleSpinBoxVoltageStep->value();
    if (m_voltageWantedValue < MIN_VOLTAGE){
        m_voltageWantedValue = MIN_VOLTAGE;
    }
    ui->lcdNumberVoltage->display(m_voltageWantedValue);
    QString cmd = "Volt: " + QString::number(m_voltageWantedValue);
    QByteArray data = cmd.toLocal8Bit();

    emit emergency(data);
}
void SupplyControl::on_pushButtonCurrentUp_clicked(bool)
{
    m_currentWantedValue += ui->doubleSpinBoxCurrentStep->value();
    if (m_currentWantedValue > MAX_CURRENT){
        m_currentWantedValue = MAX_CURRENT;
    }
    ui->lcdNumberCurrent->display(m_currentWantedValue);
    QString cmd = "Cur: " + QString::number(m_currentWantedValue);
    QByteArray data = cmd.toLocal8Bit();

    emit emergency(data);
}

void SupplyControl::on_pushButtonCurrentDown_clicked(bool)
{
    m_currentWantedValue -= ui->doubleSpinBoxCurrentStep->value();
    if (m_currentWantedValue < MIN_CURRENT){
        m_currentWantedValue = MIN_CURRENT;
    }
    ui->lcdNumberCurrent->display(m_currentWantedValue);
    QString cmd = "Cur: " + QString::number(m_currentWantedValue);
    QByteArray data = cmd.toLocal8Bit();

    emit emergency(data);
}

void SupplyControl::on_pushButtonChangeSupplyCommState_clicked(bool)
{
    QByteArray data = "Q";
    emit emergency(data);
}

void SupplyControl::on_pushButtonChangeSupplyOutputState_clicked(bool)
{
    QByteArray data = "W";
    emit emergency(data);
}
