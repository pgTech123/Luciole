#include "valueelement.h"

ValueElement::ValueElement(QWidget *parent, QString name) : AlarmElement(parent)
{
    m_lcd = new QLCDNumber(this);
    setup(name, m_lcd);
}

ValueElement::~ValueElement()
{

}
