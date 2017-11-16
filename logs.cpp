#include "logs.h"

Logs::Logs(QObject *parent) : QObject(parent)
{
    openStreams();
    for(int i = 0; i < NUM_ITEMS_MONITORED; i++) {
        m_values[i] = 0;
        m_simulated[i] = false;
    }

    m_writeTimer = new QTimer(this);
    m_writeTimer->start(WRITE_TIMER_MS);
    connect(m_writeTimer, SIGNAL(timeout()), this, SLOT(writeLogs()));
}

Logs::~Logs()
{
    m_errorStream->flush();
    m_debugStream->flush();
}

void Logs::logValue(int id, float value, bool simulated)
{
    m_values[id] = value;
    m_simulated[id] = simulated;
}

void Logs::logError(int id, bool simulated)
{
    (*m_errorStream) << getTime() << "," << ITEMS_MONITORED[id] << "," << m_values[id] << "," << simulated << endl;
}

QString Logs::getText()
{
    m_errorStream->flush();
    m_debugStream->flush();

    QFile file(ERROR_LOG_FILENAME);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QString("No errors!");

    QString str;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        str.append(line);
    }
    return str;
}

void Logs::openStreams()
{
    m_errorFile = new QFile(ERROR_LOG_FILENAME);
    m_debugFile = new QFile(DEBUG_LOG_FILENAME);

    if ( m_errorFile->open(QIODevice::ReadWrite | QIODevice::Append)) {
        m_errorStream = new QTextStream(m_errorFile);
    }
    if (m_debugFile->open(QIODevice::ReadWrite | QIODevice::Append)) {
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

    (*m_errorStream) << "Timestamp,Sensor,Value,Simulated" << endl;
}

QString Logs::getTime()
{
    qint64 date = QDateTime::currentMSecsSinceEpoch();
    return QString::number(date);
}

void Logs::writeLogs()
{
    (*m_debugStream) << getTime() << ",";
    for(int i = 0; i < NUM_ITEMS_MONITORED-1; i++) {
        (*m_debugStream) << m_values[i] << ",";
    }
    (*m_debugStream) << m_values[NUM_ITEMS_MONITORED-1] << endl;

    m_errorStream->flush();
    m_debugStream->flush();
}
