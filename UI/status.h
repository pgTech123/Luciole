#ifndef STATUS_H
#define STATUS_H

#include <QWidget>
#include <QTimer>

#define DISCONNECTION_TIMEOUT   1000    // ms

namespace Ui {
class Status;
}

class Status : public QWidget
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = 0);
    ~Status();

public slots:
    void error(int id, bool simulated);
    void valueChanged(int id, float value, bool simulated);
    void statusUpdate(unsigned char status);

private slots:
    void rs232Disconnected();

private:
    Ui::Status *ui;

    QTimer *m_disconnectionTimeout;
};

#endif // STATUS_H
