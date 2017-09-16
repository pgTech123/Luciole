#ifndef LASER_H
#define LASER_H

#include <QWidget>

namespace Ui {
class Laser;
}

class Laser : public QWidget
{
    Q_OBJECT

public:
    explicit Laser(QWidget *parent = 0);
    ~Laser();

private:
    Ui::Laser *ui;
};

#endif // LASER_H
