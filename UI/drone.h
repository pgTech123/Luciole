#ifndef DRONE_H
#define DRONE_H

#include <QWidget>

#include "valueelement.h"

namespace Ui {
class Drone;
}

class Drone : public QWidget
{
    Q_OBJECT

public:
    explicit Drone(QWidget *parent = 0);
    ~Drone();

private:
    Ui::Drone *ui;

    ValueElement *m_voltageCell1;
    ValueElement *m_voltageCell2;
    ValueElement *m_voltageCell3;
    ValueElement *m_voltageCell4;

    ValueElement *m_currentCell1;
    ValueElement *m_currentCell2;
    ValueElement *m_currentCell3;
    ValueElement *m_currentCell4;

    ValueElement *m_powerCell1;
    ValueElement *m_powerCell2;
    ValueElement *m_powerCell3;
    ValueElement *m_powerCell4;

    ValueElement *m_batVoltageCell1;
    ValueElement *m_batVoltageCell2;
    ValueElement *m_batVoltageCell3;
    ValueElement *m_batCurrent;

};

#endif // DRONE_H
