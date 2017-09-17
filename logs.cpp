#include "logs.h"

Logs::Logs(QObject *parent) : QObject(parent)
{
    openStreams();
    for(int i = 0; i < NUM_ITEMS_MONITORED; i++) {
        m_values[i] = 0;
        m_simulated[i] = false;
    }
}

void Logs::logValue(int id, float value, bool simulated)
{
    m_values[id] = value;
    m_simulated[id] = simulated;

    (*m_debugStream) << getTime() << ",";
    for(int i = 0; i < NUM_ITEMS_MONITORED-1; i++) {
        (*m_debugStream) << m_values[i] << "," << m_simulated[i] << ",";
    }
    (*m_debugStream) << m_values[NUM_ITEMS_MONITORED-1] << "," << m_simulated[NUM_ITEMS_MONITORED-1]<< endl;
}

void Logs::logError(int id, bool simulated)
{
    (*m_errorStream) << getTime() << "," << id << "," << simulated << endl;
}

QString Logs::getText()
{
    return QString(m_errorStream->readAll());
}

void Logs::openStreams()
{
    m_errorFile = new QFile(ERROR_LOG_FILENAME);
    m_debugFile = new QFile(DEBUG_LOG_FILENAME);

    if ( m_errorFile->open(QIODevice::ReadWrite)) {
        m_errorStream = new QTextStream(m_errorFile);
    }
    if (m_debugFile->open(QIODevice::ReadWrite)) {
        m_debugStream = new QTextStream(m_debugFile);
    }
}

QString Logs::getTime()
{
    QDateTime date = QDateTime::currentDateTime();
    return date.toString();
}

