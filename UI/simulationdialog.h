#ifndef SIMULATIONDIALOG_H
#define SIMULATIONDIALOG_H

#include <QDialog>

#include "constants.h"

namespace Ui {
class SimulationDialog;
}

class SimulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SimulationDialog(QWidget *parent = 0);
    ~SimulationDialog();

signals:
    void valueChanged(int id, float value, bool simulated);
    void errorSent(int id, bool simulated);

private slots:
    void on_doubleSpinBoxBatCur_valueChanged(double val);
    void on_doubleSpinBoxBatLevel_valueChanged(double val);
    void on_doubleSpinBoxCellBalancing_valueChanged(double val);
    void on_doubleSpinBoxBatCell1_valueChanged(double val);
    void on_doubleSpinBoxBatCell2_valueChanged(double val);
    void on_doubleSpinBoxBatCell3_valueChanged(double val);
    void on_doubleSpinBoxCurCell1_valueChanged(double val);
    void on_doubleSpinBoxCurCell2_valueChanged(double val);
    void on_doubleSpinBoxCurCell3_valueChanged(double val);
    void on_doubleSpinBoxCurCell4_valueChanged(double val);
    void on_doubleSpinBoxBatGlobal_valueChanged(double val);
    void on_doubleSpinBoxTempCell1_valueChanged(double val);
    void on_doubleSpinBoxTempCell2_valueChanged(double val);
    void on_doubleSpinBoxTempCell3_valueChanged(double val);
    void on_doubleSpinBoxTempCell4_valueChanged(double val);
    void on_doubleSpinBoxTempLaser1_valueChanged(double val);
    void on_doubleSpinBoxTempLaser2_valueChanged(double val);
    void on_doubleSpinBoxTempLaser3_valueChanged(double val);
    void on_doubleSpinBoxTempLaser4_valueChanged(double val);
    void on_doubleSpinBoxVoltageGlobal_valueChanged(double val);
    void on_doubleSpinBoxBatTemp_valueChanged(double val);

    void on_checkBoxBatCell1_toggled(bool checked);
    void on_checkBoxBatCell2_toggled(bool checked);
    void on_checkBoxBatCell3_toggled(bool checked);
    void on_checkBoxCurCell1_toggled(bool checked);
    void on_checkBoxCurCell2_toggled(bool checked);
    void on_checkBoxCurCell3_toggled(bool checked);
    void on_checkBoxCurCell4_toggled(bool checked);
    void on_checkBoxTempLaser1_toggled(bool checked);
    void on_checkBoxTempLaser2_toggled(bool checked);
    void on_checkBoxTempLaser3_toggled(bool checked);
    void on_checkBoxTempLaser4_toggled(bool checked);
    void on_checkBoxBatLevel_toggled(bool checked);
    void on_checkBoxTempCell1_toggled(bool checked);
    void on_checkBoxTempCell2_toggled(bool checked);
    void on_checkBoxTempCell3_toggled(bool checked);
    void on_checkBoxTempCell4_toggled(bool checked);
    void on_checkBoxBatCurrent_toggled(bool checked);
    void on_checkBoxVoltageGlobal_toggled(bool checked);
    void on_checkBoxBatGlobal_toggled(bool checked);
    void on_checkBoxCellBalancing_toggled(bool checked);
    void on_checkBoxBatTemperature_toggled(bool checked);


private:
    Ui::SimulationDialog *ui;
};

#endif // SIMULATIONDIALOG_H
