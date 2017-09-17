#include "logs.h"

Logs::Logs(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < NUM_ITEMS_MONITORED; i++) {
        m_values[i] = 0;
    }
}

void Logs::logValue(int id, float value, bool simulated)
{
    m_values[id] = value;
    m_simulated[id] = simulated;

    //TODO: log
}

void Logs::logError(int id, bool simulated)
{
    // TODO: Do not modify array simulated, possible bug...
}
