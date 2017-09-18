#ifndef RS232_UI_H
#define RS232_UI_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

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

private slots:
    void accept();
    void refreshUI();
    bool tryConnection();

private:
    Ui::Rs232_ui *ui;

    QSerialPort m_serialPort;
};

#endif // RS232_UI_H
