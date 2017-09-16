#ifndef VALUEELEMENT_H
#define VALUEELEMENT_H

#include <QLCDNumber>

#include "alarmelement.h"

class ValueElement : public AlarmElement
{
public:
    explicit ValueElement(QWidget *parent = nullptr, QString name="Unknown");
    virtual ~ValueElement();

private:
    QLCDNumber *m_lcd;
};

#endif // VALUEELEMENT_H
