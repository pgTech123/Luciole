#ifndef ALARMELEMENT_H
#define ALARMELEMENT_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

/**
 * @brief The AlarmElement class is an abstract class that manages
 * ui and sound elements associated with an alarm. This class should
 * be the parent of every items that can fail.
 *
 * This class also make sure to logs the error in the log file.
 *
 * This class include a title, a child defined widget and a clear button
 * to clear the alarm.
 *
 * -------------------------------------------------------------
 * | Item name | <Child defined widget>  | ( Clear Button  )   |
 * -------------------------------------------------------------
 */

class AlarmElement : public QWidget
{
    Q_OBJECT
public:
    explicit AlarmElement(QWidget *parent = nullptr);

protected:
    void setup(QString name, QWidget *widget);
    void triggerAlarm(bool fromSimulation);

private slots:
    void clearAlarm();

signals:
    void alarmTriggered();

private:
    void logError();
    void logClear();

private:
    QLabel *m_itemName;
    QHBoxLayout *m_layout;
    QPushButton *m_clearButton;

    bool m_alarmOn;
};

#endif // ALARMELEMENT_H
