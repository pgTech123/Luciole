#include "alarmelement.h"

AlarmElement::AlarmElement(QWidget *parent) : QWidget(parent)
{
    this->setFixedHeight(50);

    // Setup layout
    m_layout = new QHBoxLayout(this);
    m_itemName = new QLabel(this);
    m_clearButton = new QPushButton(this);

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

void AlarmElement::triggerAlarm(bool fromSimulation)
{
    m_alarmOn = true;
    logError();

    emit alarmTriggered();
}

void AlarmElement::clearAlarm()
{
    m_alarmOn = false;
    logClear();
}

void AlarmElement::logError()
{

}

void AlarmElement::logClear()
{

}

