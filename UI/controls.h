#ifndef CONTROLS_H
#define CONTROLS_H

#include <QWidget>
#include "constants.h"

namespace Ui {
class Controls;
}

class Controls : public QWidget
{
    Q_OBJECT

public:
    explicit Controls(QWidget *parent = 0);
    ~Controls();

signals:
    void emergency(QByteArray);

public slots:
    void error(int id, bool simulated);
    void valueChanged(int id, float value, bool simulated);
    void statusUpdate(unsigned char status);

private slots:
    void unlock(bool);
    void lock(bool);
    void runMode(bool);

    void on_pushButtonEmergencyStop_clicked(bool);
    void on_pushButtonRstEmergency_clicked(bool);
    void on_pushButtonChg_clicked(bool);
    void on_pushButtonDsg_clicked(bool);
    void on_pushButtonChgDsg_clicked(bool);
    void on_pushButtonReset_clicked(bool);
    void on_pushButtonStb_clicked(bool);
    void on_pushButtonVoltageDown_clicked(bool);
    void on_pushButtonVoltageUp_clicked(bool);
    void on_pushButtonCurrentUp_clicked(bool);
    void on_pushButtonCurrentDown_clicked(bool);
    void on_pushButtonChangeSupplyCommState_clicked(bool);
    void on_pushButtonChangeSupplyOutputState_clicked(bool);



private:
    Ui::Controls *ui;
};

#endif // CONTROLS_H
