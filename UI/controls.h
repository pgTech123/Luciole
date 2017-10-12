#ifndef CONTROLS_H
#define CONTROLS_H

#include <QWidget>

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

private slots:
    void unlock(bool);
    void lock(bool);

    void on_pushButtonEmergencyStop_clicked(bool);

private:
    Ui::Controls *ui;
};

#endif // CONTROLS_H
