#ifndef BATTERY_H
#define BATTERY_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "constants.h"
#include "valueelement.h"

namespace Ui {
class Battery;
}

class Battery : public QWidget
{
    Q_OBJECT

public:
    explicit Battery(QWidget *parent = 0);
    ~Battery();

public slots:
    void error(int id, bool simulated);
    void valueChanged(int id, float value, bool simulated);

private:
    void setupScene();

private:
    Ui::Battery *ui;

    ValueElement *m_batVoltageGlobal;
    ValueElement *m_batVoltageCell1;
    ValueElement *m_batVoltageCell2;
    ValueElement *m_batVoltageCell3;
    ValueElement *m_batCurrent;
    ValueElement *m_batTemperature;

    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
};

#endif // BATTERY_H
