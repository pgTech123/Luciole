#include "systems.h"
#include "ui_systems.h"

Systems::Systems(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Systems)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_clearButton = new QPushButton("Clear", this);
    m_view->setScene(m_scene);
    this->setupScene();

    ui->verticalLayout->addWidget(m_view);
    ui->verticalLayout->addWidget(m_clearButton);
    this->setLayout(ui->verticalLayout);

    m_timer->start(FLASHING_TIME_MS);

    connect(m_clearButton, SIGNAL(clicked(bool)), this, SLOT(clearErrors()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateScene()));

    this->clearErrors();
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

void Systems::valueChanged(int, float, bool)
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

    m_flashCell1 = m_scene->addEllipse(140, 95, 25, 25, QPen(), QBrush(Qt::red));
    m_flashCell2 = m_scene->addEllipse(275, 125, 25, 25, QPen(), QBrush(Qt::red));
    m_flashCell3 = m_scene->addEllipse(120, 165, 25, 25, QPen(), QBrush(Qt::red));
    m_flashCell4 = m_scene->addEllipse(250, 195, 25, 25, QPen(), QBrush(Qt::red));

    m_flashBat = m_scene->addEllipse(190, 120, 50, 50, QPen(), QBrush(Qt::red));

    m_flashLaser1 = m_scene->addEllipse(5,5,10,10);
    m_flashLaser2 = m_scene->addEllipse(5,5,10,10);
    m_flashLaser3 = m_scene->addEllipse(5,5,10,10);
    m_flashLaser4 = m_scene->addEllipse(5,5,10,10);
}

void Systems::updateScene()
{
    static bool lit = true;
    // Make invisible if false

    if (lit) {
        // Dim
        if (m_flashCell1->opacity() >= OPACITY_LOW)
            m_flashCell1->setOpacity(0.1);
        if (m_flashCell2->opacity() >= OPACITY_LOW)
            m_flashCell2->setOpacity(0.1);
        if (m_flashCell3->opacity() >= OPACITY_LOW)
            m_flashCell3->setOpacity(0.1);
        if (m_flashCell4->opacity() >= OPACITY_LOW)
            m_flashCell4->setOpacity(0.1);
        if (m_flashBat->opacity() >= OPACITY_LOW)
            m_flashBat->setOpacity(0.1);

        lit = false;
    } else {
        // Lit
        if (m_flashCell1->opacity() >= OPACITY_LOW)
            m_flashCell1->setOpacity(OPACITY_HIGH);
        if (m_flashCell2->opacity() >= OPACITY_LOW)
            m_flashCell2->setOpacity(OPACITY_HIGH);
        if (m_flashCell3->opacity() >= OPACITY_LOW)
            m_flashCell3->setOpacity(OPACITY_HIGH);
        if (m_flashCell4->opacity() >= OPACITY_LOW)
            m_flashCell4->setOpacity(OPACITY_HIGH);
        if (m_flashBat->opacity() >= OPACITY_LOW)
            m_flashBat->setOpacity(OPACITY_HIGH);

        lit = true;
    }
}

void Systems::flashCells(int id)
{
    switch (id) {
    case 0:
        m_flashCell1->setOpacity(1);
        break;
    case 1:
        m_flashCell2->setOpacity(1);
        break;
    case 2:
        m_flashCell3->setOpacity(1);
        break;
    case 3:
        m_flashCell4->setOpacity(1);
        break;
    default:
        break;
    }
}

void Systems::flashBat()
{
    m_flashBat->setOpacity(1);
}

void Systems::flashLasers(int id)
{
    switch (id) {
    case 0:
        m_flashLaser1->setOpacity(1);
        break;
    case 1:
        m_flashLaser2->setOpacity(1);
        break;
    case 2:
        m_flashLaser3->setOpacity(1);
        break;
    case 3:
        m_flashLaser4->setOpacity(1);
        break;
    default:
        break;
    }
}

void Systems::clearErrors()
{
    m_flashCell1->setOpacity(0);
    m_flashCell2->setOpacity(0);
    m_flashCell3->setOpacity(0);
    m_flashCell4->setOpacity(0);
    m_flashLaser1->setOpacity(0);
    m_flashLaser2->setOpacity(0);
    m_flashLaser3->setOpacity(0);
    m_flashLaser4->setOpacity(0);
    m_flashBat->setOpacity(0);
}
