#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <constants.h>

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPushButton>

#define IMG_RATIO           0.70


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
    void clearErrors();

private:
    Ui::Systems *ui;

    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem* m_droneImg;

    QPushButton *m_clearButton;
};

#endif // SYSTEMS_H
