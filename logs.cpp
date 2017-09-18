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
        (*m_debugStream) << m_values[i] << ",";
    }
    (*m_debugStream) << m_values[NUM_ITEMS_MONITORED-1] << endl;
}

void Logs::logError(int id, bool simulated)
{
    (*m_errorStream) << getTime() << "," << ITEMS_MONITORED[id] << "," << simulated << endl;
}

QString Logs::getText()
{
    m_errorStream->flush();
    m_debugStream->flush();
    return QString(m_errorFile->readLine());    //TODO: This is not working...
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
    this->writeTags();
}

void Logs::writeTags()
{
    (*m_debugStream) << "Timestamp";
    for(int i = 0; i < NUM_ITEMS_MONITORED; i++) {
        (*m_debugStream) << "," << ITEMS_MONITORED[i];
    }
    (*m_debugStream) << endl;

    (*m_errorStream) << "Timestamp,Sensor,Simulated" << endl;
}

QString Logs::getTime()
{
    QDateTime date = QDateTime::currentDateTime();
    return date.toString();
}

