#include "rs232_ui.h"
#include "ui_rs232_ui.h"

Rs232_ui::Rs232_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rs232_ui)
{
    ui->setupUi(this);
    this->refreshUI();
    connect(ui->pushButtonRefresh, SIGNAL(clicked(bool)), this, SLOT(refreshUI()));
}

Rs232_ui::~Rs232_ui()
{
    delete ui;
}

void Rs232_ui::accept()
{
    if(this->tryConnection()){
        QDialog::accept();
    } else {
        // Display warning
        QMessageBox msgBox;
        int err = m_serialPort.error();
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Unable to connect to serial port " + ui->comboBoxPort->currentText());
        msgBox.setInformativeText(QString("Error: ") + QString::number(err) + QString(" ") +
                                  m_serialPort.errorString());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void Rs232_ui::refreshUI()
{
    // Ports combo box
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    ui->comboBoxPort->clear();
    for(int i = 0; i < ports.size(); i++) {
        QString portName = ports[i].portName();
        ui->comboBoxPort->addItem(portName);
    }

    // Baud rate combo box
    ui->comboBoxBaudRate->clear();
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud1200));
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud2400));
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud4800));
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud9600));
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud19200));
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud38400));
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud57600));
    ui->comboBoxBaudRate->addItem(QString::number(QSerialPort::Baud115200));
    ui->comboBoxBaudRate->setCurrentIndex(5);
}

bool Rs232_ui::tryConnection()
{

    QString serialPortName = ui->comboBoxPort->currentText();
    m_serialPort.setPortName(serialPortName);

    qint32 serialPortBaudRate = ui->comboBoxBaudRate->currentText().toInt();
    m_serialPort.setBaudRate(serialPortBaudRate);

    if (!m_serialPort.open(QIODevice::ReadWrite)) {
        return false;
    }

    connect(&m_serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(&m_serialPort, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(errorComm(QSerialPort::SerialPortError)));

    return true;
}

void Rs232_ui::readData()
{
    // Mapping is NOT thread safe. We assume the only place we fill and empty
    // the mapping buffer is this function.
    m_mapping.append(m_serialPort.readAll());
    if(m_mapping.frameReady()) {
        Frame frame = m_mapping.readFrame();
        for (int i = 0; i < NUM_ITEMS_MONITORED; i++) {
            emit valueChanged(i, frame.values[i], false);
            if (frame.errors[i]) {
                emit errorSent(i, false);
            }
        }
    }
}

bool Rs232_ui::writeData(const QByteArray &writeData)
{
    qint64 bytesWritten = m_serialPort.write(writeData);
    if(bytesWritten != writeData.size()) {
        return false;
    }
    return true;
}

void Rs232_ui::errorComm(QSerialPort::SerialPortError)
{
    //TODO: log comm error
}
