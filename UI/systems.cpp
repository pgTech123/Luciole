#include "systems.h"
#include "ui_systems.h"

Systems::Systems(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Systems)
{
    ui->setupUi(this);

    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_clearButton = new QPushButton("Clear", this);
    m_view->setScene(m_scene);
    this->setupScene();

    ui->verticalLayout->addWidget(m_view);
    ui->verticalLayout->addWidget(m_clearButton);
    this->setLayout(ui->verticalLayout);

    connect(m_clearButton, SIGNAL(clicked(bool)), this, SLOT(clearErrors()));
}

Systems::~Systems()
{
    delete ui;
}

void Systems::error(int id, bool simulated)
{
    if (id >= TEMPERATURE_CELL1 && id <= TEMPERATURE_CELL4 ) {
        flashCells(id-TEMPERATURE_CELL1);
    }
    else if (id == VOLTAGE_GLOBAL) {
        flashCells(0);
        flashCells(1);
        flashCells(2);
        flashCells(3);
    }
    else if (id >= CURRENT_CELL1 && id <= CURRENT_CELL4) {
        flashCells(id-CURRENT_CELL1);
    }
    else if (id >= TEMPERATURE_LASER1 && id <= TEMPERATURE_LASER4) {
        flashLasers(id-TEMPERATURE_LASER1);
    }
    else if (id >= BAT_CELL1 && id <= BAT_LEVEL) {
        flashBat();
    }
}

void Systems::valueChanged(int id, float value, bool simulated)
{
    //Unused
}

void Systems::setupScene()
{
    // Set Background black
    m_scene->setBackgroundBrush(QBrush(QColor(255,255,255)));

    m_droneImg = new QGraphicsPixmapItem(QPixmap(":/images/Ressources/drone.jpg"));
    m_droneImg->setScale(IMG_RATIO);
    m_scene->addItem(m_droneImg);

}


void Systems::flashCells(int id)
{
    //TODO
}

void Systems::flashBat()
{
    //TODO
}

void Systems::flashLasers(int id)
{
    //TODO
}

void Systems::clearErrors()
{
    //TODO
}
