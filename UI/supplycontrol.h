#ifndef SUPPLYCONTROL_H
#define SUPPLYCONTROL_H

#include <QWidget>
#include "constants.h"

#define MAX_VOLTAGE     15  // V
#define MAX_CURRENT     5   // A

#define MIN_VOLTAGE     0   // V
#define MIN_CURRENT     0   // A

namespace Ui {
class SupplyControl;
}

class SupplyControl : public QWidget
{
    Q_OBJECT

public:
    explicit SupplyControl(QWidget *parent = 0);
    ~SupplyControl();

signals:
    void emergency(QByteArray);

public slots:
    void error(int id, bool simulated);
    void valueChanged(int id, float value, bool simulated);

    void on_pushButtonVoltageDown_clicked(bool);
    void on_pushButtonVoltageUp_clicked(bool);
    void on_doubleSpinBoxVoltageStep_valueChanged(double);
    void on_doubleSpinBoxCurrentStep_valueChanged(double);
    void on_pushButtonCurrentUp_clicked(bool);
    void on_pushButtonCurrentDown_clicked(bool);
    void on_pushButtonChangeSupplyCommState_clicked(bool);
    void on_pushButtonChangeSupplyOutputState_clicked(bool);

private:
    Ui::SupplyControl *ui;

    float m_voltageWantedValue;
    float m_currentWantedValue;
};

#endif // SUPPLYCONTROL_H
