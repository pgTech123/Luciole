#ifndef BATTERY_H
#define BATTERY_H

#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "constants.h"
#include "valueelement.h"
#include "graphbarelement.h"

#define IMG_RATIO           0.6
#define UPDATE_FREQ_MS      500

enum States {
    IDLE, CHARGING, DISCHARGING, BALANCING
};

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

private slots:
    void update();

private:
    Ui::Battery *ui;

    ValueElement *m_batVoltageGlobal;
    ValueElement *m_batVoltageCell1;
    ValueElement *m_batVoltageCell2;
    ValueElement *m_batVoltageCell3;
    ValueElement *m_batCurrent;
    ValueElement *m_batTemperature;
    GraphBarElement *m_batteryLevel;

    QLabel *m_bmsGain;
    QLabel *m_bmsOffset;

    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem* m_balancingImg;
    QGraphicsPixmapItem* m_batteryImg;

    States m_batteryState;

    QTimer *m_flashBattery;

};

#endif // BATTERY_H
