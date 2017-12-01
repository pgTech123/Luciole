#ifndef DRONE_H
#define DRONE_H

#include <QWidget>

#include "valueelement.h"
#include "constants.h"

namespace Ui {
class Drone;
}

class Drone : public QWidget
{
    Q_OBJECT

public:
    explicit Drone(QWidget *parent = 0);
    ~Drone();

public slots:
    void error(int id, bool simulated);
    void valueChanged(int id, float value, bool simulated);

private:
    Ui::Drone *ui;

    ValueElement *m_voltageGlobal;

    ValueElement *m_temperatureCell1;
    ValueElement *m_temperatureCell2;
    ValueElement *m_temperatureCell3;
    ValueElement *m_temperatureCell4;

    ValueElement *m_currentCell1;
    ValueElement *m_currentCell2;
    ValueElement *m_currentCell3;
    ValueElement *m_currentCell4;

    ValueElement *m_efficiencyCell1;
    ValueElement *m_efficiencyCell2;
    ValueElement *m_efficiencyCell3;
    ValueElement *m_efficiencyCell4;


    /*ValueElement *m_powerCell1;
    ValueElement *m_powerCell2;
    ValueElement *m_powerCell3;
    ValueElement *m_powerCell4;*/

    float m_currentBat;

};

#endif // DRONE_H
