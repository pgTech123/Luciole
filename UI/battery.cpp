#include "battery.h"
#include "ui_battery.h"

Battery::Battery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battery)
{
    ui->setupUi(this);

    m_batteryState = IDLE;

    m_flashBattery = new QTimer(this);
    m_flashBattery->start(UPDATE_FREQ_MS);
    connect(m_flashBattery, SIGNAL(timeout()), this, SLOT(update()));

    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_view->setScene(m_scene);
    this->setupScene();

    m_batVoltageGlobal = new ValueElement(this, "Battery Voltage Global");
    m_batVoltageCell1 = new ValueElement(this, "Battery Voltage Cell 1");
    m_batVoltageCell2 = new ValueElement(this, "Battery Voltage Cell 2");
    m_batVoltageCell3 = new ValueElement(this, "Battery Voltage Cell 3");
    m_batCurrent = new ValueElement(this, "Battery Current");
    m_batTemperature = new ValueElement(this, "Battery Temperature");
    m_batteryLevel = new GraphBarElement(this, "Battery Level");
    m_bmsGain = new QLabel(this);
    m_bmsOffset = new QLabel(this);
    m_bmsGain->setText("Gain: Unknown");
    m_bmsOffset->setText("Offset: Unknown");

    ui->verticalLayout->addWidget(m_batVoltageGlobal);
    ui->verticalLayout->addWidget(m_batVoltageCell1);
    ui->verticalLayout->addWidget(m_batVoltageCell2);
    ui->verticalLayout->addWidget(m_batVoltageCell3);
    ui->verticalLayout->addWidget(m_batCurrent);
    ui->verticalLayout->addWidget(m_batTemperature);
    ui->verticalLayout->addWidget(m_batteryLevel);
    ui->verticalLayout->addWidget(m_view);
    ui->verticalLayout->addWidget(m_bmsGain);
    ui->verticalLayout->addWidget(m_bmsOffset);

    this->setLayout(ui->verticalLayout);
}

Battery::~Battery()
{
    delete ui;
}

void Battery::error(int id, bool simulated)
{
    switch (id) {
    case BAT_TOT:
        m_batVoltageGlobal->triggerAlarm(simulated);
        break;
    case BAT_CELL1:
        m_batVoltageCell1->triggerAlarm(simulated);
        break;
    case BAT_CELL2:
        m_batVoltageCell2->triggerAlarm(simulated);
        break;
    case BAT_CELL3:
        m_batVoltageCell3->triggerAlarm(simulated);
        break;
    case BAT_CURRENT:
        m_batCurrent->triggerAlarm(simulated);
        break;
    case BAT_TEMPERATURE:
        m_batTemperature->triggerAlarm(simulated);
        break;
    case BAT_LEVEL:
        m_batteryLevel->triggerAlarm(simulated);
        break;
    default:
        break;
    }
}

void Battery::valueChanged(int id, float value, bool)
{
    switch (id) {
    case BAT_TOT:
        m_batVoltageGlobal->setValue(value);
        break;
    case BAT_CELL1:
        m_batVoltageCell1->setValue(value);
        break;
    case BAT_CELL2:
        m_batVoltageCell2->setValue(value);
        break;
    case BAT_CELL3:
        m_batVoltageCell3->setValue(value);
        break;
    case BAT_CURRENT:
        m_batCurrent->setValue(value);
        break;
    case BAT_TEMPERATURE:
        m_batTemperature->setValue(value);
        break;
    case BAT_LEVEL:
        m_batteryLevel->setValue(value);
        break;
    case BAT_CELL_BALANCING:
        if(value > 0) { m_batteryState = BALANCING;}
        else {
            if(m_batCurrent->getValue() == 0 ) m_batteryState = IDLE;
            else if(m_batCurrent->getValue() > 0) m_batteryState = CHARGING;
            else m_batteryState = DISCHARGING;
        }
        break;
    case BMS_GAIN:
        m_bmsGain->setText("Gain: " + QString::number(value));
        break;
    case BMS_OFFSET:
        m_bmsOffset->setText("Offset: " + QString::number(value));
        break;
    default:
        break;
    }
}

void Battery::setupScene()
{
    // Set Background black
    m_scene->setBackgroundBrush(QBrush(QColor(0,0,0)));

    m_balancingImg = new QGraphicsPixmapItem(QPixmap(":/images/Ressources/balancing.jpg"));
    m_batteryImg = new QGraphicsPixmapItem(QPixmap(":/images/Ressources/battery.jpg"));
    m_balancingImg->setScale(IMG_RATIO);
    m_batteryImg->setScale(IMG_RATIO);
    m_scene->addItem(m_balancingImg);
    m_scene->addItem(m_batteryImg);
    m_balancingImg->setOpacity(0);

}

void Battery::update()
{
    static bool transparent = true;
    if (m_batteryState == BALANCING && transparent) {
        m_balancingImg->setOpacity(1);
        m_batteryImg->setOpacity(0);
        transparent = false;
    } else if(m_batteryState == BALANCING && !transparent) {
        m_balancingImg->setOpacity(0.65);
        m_batteryImg->setOpacity(0);
        transparent = true;
    } else {
        m_balancingImg->setOpacity(0.0);
        m_batteryImg->setOpacity(1);
    }
}
