#include "valueelement.h"

ValueElement::ValueElement(QWidget *parent, QString name, bool vertical) : AlarmElement(parent, vertical)
{
    m_lcd = new QLCDNumber(this);
    setup(name, m_lcd);
}

ValueElement::~ValueElement()
{

}

void ValueElement::setValue(float value)
{
    m_lcd->display(value);
}

float ValueElement::getValue()
{
    return m_lcd->value();
}
