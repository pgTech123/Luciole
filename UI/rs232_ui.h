#ifndef RS232_UI_H
#define RS232_UI_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QByteArray>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "RS232/mapping.h"

namespace Ui {
class Rs232_ui;
}

class Rs232_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Rs232_ui(QWidget *parent = 0);
    ~Rs232_ui();

signals:
    void valueChanged(int id, float value, bool simulated);
    void errorSent(int id, bool simulated);

public slots:
    bool writeData(const QByteArray &writeData);

private slots:
    void accept();
    void refreshUI();
    bool tryConnection();

    void readData();
    void errorComm(QSerialPort::SerialPortError);

private:
    Ui::Rs232_ui *ui;

    QSerialPort m_serialPort;
    QByteArray  m_readData;

    Mapping m_mapping;
};

#endif // RS232_UI_H
