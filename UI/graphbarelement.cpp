#include "graphbarelement.h"

GraphBarElement::GraphBarElement(QWidget *parent, QString name, bool vertical) : AlarmElement(parent, vertical)
{
    m_progressBar = new QProgressBar(this);
    setup(name, m_progressBar);
}

GraphBarElement::~GraphBarElement()
{

}

void GraphBarElement::setValue(float value)
{
    m_progressBar->setValue(value);
}

float GraphBarElement::getValue()
{
    return m_progressBar->value();
}

void GraphBarElement::setMax(float maxValue)
{
    m_progressBar->setMaximum(maxValue);
}
