#ifndef GRAPHBARELEMENT_H
#define GRAPHBARELEMENT_H

#include <QProgressBar>

#include "alarmelement.h"

class GraphBarElement : public AlarmElement
{
public:
    explicit GraphBarElement(QWidget *parent = nullptr, QString name="Unknown", bool vertical=false);
    virtual ~GraphBarElement();

    void setValue(float value);
    float getValue();

    void setMax(float maxValue);

private:
    QProgressBar *m_progressBar;
};

#endif // GRAPHBARELEMENT_H
