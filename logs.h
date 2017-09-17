#ifndef LOGS_H
#define LOGS_H

#include <QObject>
#include "constants.h"

class Logs : public QObject
{
    Q_OBJECT
public:
    explicit Logs(QObject *parent = nullptr);

public slots:
    void logValue(int id, float value, bool simulated);
    void logError(int id, bool simulated);

private:
    float m_values[NUM_ITEMS_MONITORED];
    bool m_simulated[NUM_ITEMS_MONITORED];
};

#endif // LOGS_H
