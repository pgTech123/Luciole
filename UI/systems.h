#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <QWidget>

namespace Ui {
class Systems;
}

class Systems : public QWidget
{
    Q_OBJECT

public:
    explicit Systems(QWidget *parent = 0);
    ~Systems();

private:
    Ui::Systems *ui;
};

#endif // SYSTEMS_H
