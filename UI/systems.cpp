#include "systems.h"
#include "ui_systems.h"

Systems::Systems(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Systems)
{
    ui->setupUi(this);

    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_view->setScene(m_scene);
    this->setupScene();

    ui->verticalLayout->addWidget(m_view);
    this->setLayout(ui->verticalLayout);
}

Systems::~Systems()
{
    delete ui;
}

void Systems::error(int id, bool simulated)
{

}

void Systems::valueChanged(int id, float value, bool simulated)
{

}
void Systems::setupScene()
{
    // Set Background black
    m_scene->setBackgroundBrush(QBrush(QColor(255,255,255)));

    m_droneImg = new QGraphicsPixmapItem(QPixmap(":/images/Ressources/drone.jpg"));
    m_droneImg->setScale(IMG_RATIO);
    m_scene->addItem(m_droneImg);

}
