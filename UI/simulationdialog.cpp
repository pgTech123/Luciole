#include "simulationdialog.h"
#include "ui_simulationdialog.h"

SimulationDialog::SimulationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulationDialog)
{
    ui->setupUi(this);
}

SimulationDialog::~SimulationDialog()
{
    delete ui;
}

void SimulationDialog::on_doubleSpinBoxBatCur_valueChanged(double val)
{
    emit valueChanged(BAT_CURRENT, val, true);
}

void SimulationDialog::on_doubleSpinBoxBatLevel_valueChanged(double val)
{
    emit valueChanged(BAT_LEVEL, val, true);
}

void SimulationDialog::on_doubleSpinBoxCellBalancing_valueChanged(double val)
{
    emit valueChanged(BAT_CELL_BALANCING, val, true);
}

void SimulationDialog::on_doubleSpinBoxBatCell1_valueChanged(double val)
{
    emit valueChanged(BAT_CELL1, val, true);
}

void SimulationDialog::on_doubleSpinBoxBatCell2_valueChanged(double val)
{
    emit valueChanged(BAT_CELL2, val, true);
}

void SimulationDialog::on_doubleSpinBoxBatCell3_valueChanged(double val)
{
    emit valueChanged(BAT_CELL3, val, true);
}

void SimulationDialog::on_doubleSpinBoxCurCell1_valueChanged(double val)
{
    emit valueChanged(CURRENT_CELL1, val, true);
}

void SimulationDialog::on_doubleSpinBoxCurCell2_valueChanged(double val)
{
    emit valueChanged(CURRENT_CELL2, val, true);
}

void SimulationDialog::on_doubleSpinBoxCurCell3_valueChanged(double val)
{
    emit valueChanged(CURRENT_CELL3, val, true);
}

void SimulationDialog::on_doubleSpinBoxCurCell4_valueChanged(double val)
{
    emit valueChanged(CURRENT_CELL4, val, true);
}

void SimulationDialog::on_doubleSpinBoxBatGlobal_valueChanged(double val)
{
    emit valueChanged(BAT_TOT, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempCell1_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_CELL1, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempCell2_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_CELL2, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempCell3_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_CELL3, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempCell4_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_CELL4, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempLaser1_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_LASER1, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempLaser2_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_LASER2, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempLaser3_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_LASER3, val, true);
}

void SimulationDialog::on_doubleSpinBoxTempLaser4_valueChanged(double val)
{
    emit valueChanged(TEMPERATURE_LASER4, val, true);
}

void SimulationDialog::on_doubleSpinBoxVoltageGlobal_valueChanged(double val)
{
    emit valueChanged(VOLTAGE_GLOBAL, val, true);
}

void SimulationDialog::on_doubleSpinBoxBatTemp_valueChanged(double val)
{
    emit valueChanged(BAT_TEMPERATURE, val, true);
}

//-------------------------------------------------------------
//-------------------------------------------------------------

void SimulationDialog::on_checkBoxBatCell1_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_CELL1, true);
    }
}

void SimulationDialog::on_checkBoxBatCell2_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_CELL2, true);
    }
}

void SimulationDialog::on_checkBoxBatCell3_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_CELL3, true);
    }
}

void SimulationDialog::on_checkBoxCurCell1_toggled(bool checked)
{
    if(checked) {
        emit errorSent(CURRENT_CELL1, true);
    }
}

void SimulationDialog::on_checkBoxCurCell2_toggled(bool checked)
{
    if(checked) {
        emit errorSent(CURRENT_CELL2, true);
    }
}

void SimulationDialog::on_checkBoxCurCell3_toggled(bool checked)
{
    if(checked) {
        emit errorSent(CURRENT_CELL3, true);
    }
}

void SimulationDialog::on_checkBoxCurCell4_toggled(bool checked)
{
    if(checked) {
        emit errorSent(CURRENT_CELL4, true);
    }
}

void SimulationDialog::on_checkBoxTempLaser1_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_LASER1, true);
    }
}

void SimulationDialog::on_checkBoxTempLaser2_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_LASER2, true);
    }
}

void SimulationDialog::on_checkBoxTempLaser3_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_LASER3, true);
    }
}

void SimulationDialog::on_checkBoxTempLaser4_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_LASER4, true);
    }
}

void SimulationDialog::on_checkBoxBatLevel_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_CELL1, true);
    }
}

void SimulationDialog::on_checkBoxTempCell1_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_CELL1, true);
    }
}

void SimulationDialog::on_checkBoxTempCell2_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_CELL2, true);
    }
}

void SimulationDialog::on_checkBoxTempCell3_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_CELL3, true);
    }
}

void SimulationDialog::on_checkBoxTempCell4_toggled(bool checked)
{
    if(checked) {
        emit errorSent(TEMPERATURE_CELL4, true);
    }
}

void SimulationDialog::on_checkBoxBatCurrent_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_CURRENT, true);
    }
}

void SimulationDialog::on_checkBoxVoltageGlobal_toggled(bool checked)
{
    if(checked) {
        emit errorSent(VOLTAGE_GLOBAL, true);
    }
}

void SimulationDialog::on_checkBoxBatGlobal_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_TOT, true);
    }
}

void SimulationDialog::on_checkBoxCellBalancing_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_CELL_BALANCING, true);
    }
}

void SimulationDialog::on_checkBoxBatTemperature_toggled(bool checked)
{
    if(checked) {
        emit errorSent(BAT_TEMPERATURE, true);
    }
}

