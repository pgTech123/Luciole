#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#define IMG_RATIO           0.75


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

private:
    Ui::Systems *ui;

    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem* m_droneImg;
};

#endif // SYSTEMS_H
