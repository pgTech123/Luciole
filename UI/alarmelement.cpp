#include "alarmelement.h"

AlarmElement::AlarmElement(QWidget *parent, bool vertical) : QWidget(parent)
{
    // Setup layout
    if(vertical){
        m_layout = new QVBoxLayout(this);
    } else {
        m_layout = new QHBoxLayout(this);
        this->setFixedHeight(45);
    }
    m_itemName = new QLabel(this);
    m_clearButton = new QPushButton(this);

    m_backgroundColorState = false;
    m_flashTimer = new QTimer(this);
    m_flashTimer->setSingleShot(false);
    m_flashTimer->start(FLASH_MS);
    connect(m_flashTimer, SIGNAL(timeout()), this, SLOT(updateBackgroundColor()));

    m_alarmOn = false;

    this->setLayout(m_layout);
}

void AlarmElement::setup(QString name, QWidget *widget)
{
    m_itemName->setText(name);
    m_clearButton->setText("Clear");

    m_layout->addWidget(m_itemName);
    m_layout->addWidget(widget);
    m_layout->addWidget(m_clearButton);

    connect(m_clearButton, SIGNAL(clicked(bool)), this, SLOT(clearAlarm()));
}

void AlarmElement::triggerAlarm(bool)
{
    m_alarmOn = true;
    setBackgroundColorToRed();
}

void AlarmElement::clearAlarm()
{
    m_alarmOn = false;
    setBackgroundColorToGray();
}

void AlarmElement::updateBackgroundColor()
{
    if(m_alarmOn) {
        if(m_backgroundColorState) {
            setBackgroundColorToRed();
            m_backgroundColorState = false;
        } else {
            setBackgroundColorToMidRed();
            m_backgroundColorState = true;
        }
    }
}

void AlarmElement::setBackgroundColorToRed()
{
    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void AlarmElement::setBackgroundColorToMidRed()
{
    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, QColor(255, 120, 120));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void AlarmElement::setBackgroundColorToGray()
{
    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, QColor(235, 235, 235));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

