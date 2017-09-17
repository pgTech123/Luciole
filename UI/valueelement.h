#ifndef VALUEELEMENT_H
#define VALUEELEMENT_H

#include <QLCDNumber>

#include "alarmelement.h"

class ValueElement : public AlarmElement
{
public:
    explicit ValueElement(QWidget *parent = nullptr, QString name="Unknown", bool vertical=false);
    virtual ~ValueElement();

    void setValue(float value);
    float getValue();


private:
    QLCDNumber *m_lcd;
};

#endif // VALUEELEMENT_H
