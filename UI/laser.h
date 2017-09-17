#ifndef LASER_H
#define LASER_H

#include <QWidget>

#include "constants.h"
#include "valueelement.h"

namespace Ui {
class Laser;
}

class Laser : public QWidget
{
    Q_OBJECT

public:
    explicit Laser(QWidget *parent = 0);
    ~Laser();

public slots:
    void error(int id, bool simulated);
    void valueChanged(int id, float value, bool simulated);


private:
    Ui::Laser *ui;

    ValueElement *m_TemperatureLaser1;
    ValueElement *m_TemperatureLaser2;
    ValueElement *m_TemperatureLaser3;
    ValueElement *m_TemperatureLaser4;

};

#endif // LASER_H
