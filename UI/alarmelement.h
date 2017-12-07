#ifndef ALARMELEMENT_H
#define ALARMELEMENT_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QHBoxLayout>
#include <QPushButton>

#define FLASH_MS    500

#define RESET_BY_TIMER  true
#define RESET_TIME      2000    // ms

/**
 * @brief The AlarmElement class is an abstract class that manages
 * ui and sound elements associated with an alarm. This class should
 * be the parent of every items that can fail.
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
    explicit AlarmElement(QWidget *parent = nullptr, bool vertical=false);
    void triggerAlarm(bool fromSimulation);

protected:
    void setup(QString name, QWidget *widget);

private slots:
    void clearAlarm();
    void updateBackgroundColor();

private:
    void setBackgroundColorToRed();
    void setBackgroundColorToMidRed();
    void setBackgroundColorToGray();


private:
    QLabel *m_itemName;
    QLayout *m_layout;
    QPushButton *m_clearButton;

    bool m_alarmOn;
    bool m_backgroundColorState;
    QTimer *m_flashTimer;
    QTimer *m_resetTimer;
};

#endif // ALARMELEMENT_H
