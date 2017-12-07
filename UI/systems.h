#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <constants.h>
#include <UI/alarmelement.h>

#include <QTimer>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPushButton>

#define FLASHING_TIME_MS    150
#define IMG_RATIO           0.70

#define OPACITY_LOW         0.1
#define OPACITY_HIGH        0.7

namespace Ui {
class Systems;
}

class Systems : public QWidget
{
    Q_OBJECT

public:
    explicit Systems(QWidget *parent = 0);
    ~Systems();

public slots:
    void error(int id, bool simulated);
    void valueChanged(int id, float value, bool simulated);

private:
    void setupScene();

    void flashCells(int id);
    void flashBat();
    void flashLasers(int id);

private slots:
    void updateScene();
    void clearErrors();

private:
    Ui::Systems *ui;

    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem* m_droneImg;

    QPushButton *m_clearButton;

    QTimer *m_timer;
    QTimer *m_resetTimer;

    QGraphicsEllipseItem *m_flashCell1;
    QGraphicsEllipseItem *m_flashCell2;
    QGraphicsEllipseItem *m_flashCell3;
    QGraphicsEllipseItem *m_flashCell4;
    QGraphicsEllipseItem *m_flashLaser1;
    QGraphicsEllipseItem *m_flashLaser2;
    QGraphicsEllipseItem *m_flashLaser3;
    QGraphicsEllipseItem *m_flashLaser4;
    QGraphicsEllipseItem *m_flashBat;
};

#endif // SYSTEMS_H
