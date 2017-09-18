#ifndef LOGS_H
#define LOGS_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include "constants.h"

#define ERROR_LOG_FILENAME  "error_log.csv"
#define DEBUG_LOG_FILENAME "debug_log.csv"

class Logs : public QObject
{
    Q_OBJECT
public:
    explicit Logs(QObject *parent = nullptr);

    QString getText();

public slots:
    void logValue(int id, float value, bool simulated);
    void logError(int id, bool simulated);

private:
    void openStreams();
    void writeTags();
    QString getTime();

private:
    float m_values[NUM_ITEMS_MONITORED];
    bool m_simulated[NUM_ITEMS_MONITORED];

    QFile *m_errorFile;
    QFile *m_debugFile;

    QTextStream *m_errorStream;
    QTextStream *m_debugStream;
};

#endif // LOGS_H
