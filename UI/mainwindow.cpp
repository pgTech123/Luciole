#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->gridLayout);

    m_logs = new Logs(this);

    // Child Widgets
    m_uiBattery = new Battery(this);
    m_uiControls = new Controls(this);
    m_uiDrone = new Drone(this);
    m_uiLaser = new Laser(this);
    m_uiSystems = new Systems(this);

    // Menu Widgets
    m_aboutUs = new AboutUs();
    m_rs232 = new Rs232_ui();
    m_simulation = new SimulationDialog();
    m_logsUI = new LogDialog();
    m_logsUI->setLogMaster(m_logs); // Shitty way... Passing ref instead of doing a singleton.

    // Setup child widgets
    this->setupSubWidgets();

    // Signals menu
    connect(ui->actionConnect, SIGNAL(triggered(bool)), this, SLOT(showConnectWidget()));
    connect(ui->actionReset, SIGNAL(triggered(bool)), this, SLOT(showResetDialog()));
    connect(ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->actionSimulation, SIGNAL(triggered(bool)), this,SLOT(showSimulationWidget()));
    connect(ui->actionLogs, SIGNAL(triggered(bool)), this, SLOT(showLogWidget()));
    connect(ui->actionAbout_us, SIGNAL(triggered(bool)), this, SLOT(showAboutUsWidget()));

    // Signals core.
    connect(m_simulation, SIGNAL(errorSent(int,bool)), m_uiBattery, SLOT(error(int,bool)));
    connect(m_simulation, SIGNAL(errorSent(int,bool)), m_uiControls, SLOT(error(int,bool)));
    connect(m_simulation, SIGNAL(errorSent(int,bool)), m_uiDrone, SLOT(error(int,bool)));
    connect(m_simulation, SIGNAL(errorSent(int,bool)), m_uiLaser, SLOT(error(int,bool)));
    connect(m_simulation, SIGNAL(errorSent(int,bool)), m_uiSystems, SLOT(error(int,bool)));

    connect(m_simulation, SIGNAL(valueChanged(int,float,bool)), m_uiBattery, SLOT(valueChanged(int,float,bool)));
    connect(m_simulation, SIGNAL(valueChanged(int,float,bool)), m_uiControls, SLOT(valueChanged(int,float,bool)));
    connect(m_simulation, SIGNAL(valueChanged(int,float,bool)), m_uiDrone, SLOT(valueChanged(int,float,bool)));
    connect(m_simulation, SIGNAL(valueChanged(int,float,bool)), m_uiLaser, SLOT(valueChanged(int,float,bool)));
    connect(m_simulation, SIGNAL(valueChanged(int,float,bool)), m_uiSystems, SLOT(valueChanged(int,float,bool)));

    connect(m_rs232, SIGNAL(errorSent(int,bool)), m_uiBattery, SLOT(error(int,bool)));
    connect(m_rs232, SIGNAL(errorSent(int,bool)), m_uiControls, SLOT(error(int,bool)));
    connect(m_rs232, SIGNAL(errorSent(int,bool)), m_uiDrone, SLOT(error(int,bool)));
    connect(m_rs232, SIGNAL(errorSent(int,bool)), m_uiLaser, SLOT(error(int,bool)));
    connect(m_rs232, SIGNAL(errorSent(int,bool)), m_uiSystems, SLOT(error(int,bool)));

    connect(m_rs232, SIGNAL(valueChanged(int,float,bool)), m_uiBattery, SLOT(valueChanged(int,float,bool)));
    connect(m_rs232, SIGNAL(valueChanged(int,float,bool)), m_uiControls, SLOT(valueChanged(int,float,bool)));
    connect(m_rs232, SIGNAL(valueChanged(int,float,bool)), m_uiDrone, SLOT(valueChanged(int,float,bool)));
    connect(m_rs232, SIGNAL(valueChanged(int,float,bool)), m_uiLaser, SLOT(valueChanged(int,float,bool)));
    connect(m_rs232, SIGNAL(valueChanged(int,float,bool)), m_uiSystems, SLOT(valueChanged(int,float,bool)));

    // Logs
    connect(m_simulation, SIGNAL(errorSent(int,bool)), m_logs, SLOT(logError(int,bool)));
    connect(m_simulation, SIGNAL(valueChanged(int,float,bool)), m_logs, SLOT(logValue(int,float,bool)));
    connect(m_rs232, SIGNAL(errorSent(int,bool)), m_logs, SLOT(logError(int,bool)));
    connect(m_rs232, SIGNAL(valueChanged(int,float,bool)), m_logs, SLOT(logValue(int,float,bool)));

    // Emergency
    connect(m_uiControls, SIGNAL(emergency(QByteArray)), m_rs232, SLOT(writeData(QByteArray)));
    connect(this, SIGNAL(emergency(QByteArray)), m_rs232, SLOT(writeData(QByteArray)));

    // Status
    connect(m_rs232, SIGNAL(statusUpdate(unsigned char)), m_uiControls, SLOT(statusUpdate(unsigned char)));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_aboutUs;
    delete m_rs232;
    delete m_simulation;
    delete m_logsUI;
}

void MainWindow::setupSubWidgets()
{
    ui->verticalLayoutBattery->addWidget(m_uiBattery);
    ui->verticalLayoutControls->addWidget(m_uiControls);
    ui->verticalLayoutDrone->addWidget(m_uiDrone);
    ui->verticalLayoutLaser->addWidget(m_uiLaser);
    ui->verticalLayoutSystems->addWidget(m_uiSystems);

    ui->groupBoxBattery->setLayout(ui->verticalLayoutBattery);
    ui->groupBoxControls->setLayout(ui->verticalLayoutControls);
    ui->groupBoxDrone->setLayout(ui->verticalLayoutDrone);
    ui->groupBoxLaser->setLayout(ui->verticalLayoutLaser);
    ui->groupBoxSystems->setLayout(ui->verticalLayoutSystems);
}

void MainWindow::showConnectWidget()
{
    m_rs232->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            m_rs232->size(),
            qApp->desktop()->availableGeometry()
        ));
    m_rs232->show();
    m_rs232->activateWindow();
}

void MainWindow::showResetDialog()
{
    // Display warning
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Are you sure you want to go back in startup mode?");
    //msgBox.setInformativeText("");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int answer = msgBox.exec();
    if(answer == QMessageBox::Yes) {
        QByteArray data = "T";
        emit emergency(data);
    }
}

void MainWindow::showSimulationWidget()
{
    m_simulation->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            m_simulation->size(),
            qApp->desktop()->availableGeometry()
        ));
    m_simulation->show();
    m_simulation->activateWindow();
}

void MainWindow::showLogWidget()
{
    m_logsUI->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            m_logsUI->size(),
            qApp->desktop()->availableGeometry()
        ));
    m_logsUI->show();
    m_logsUI->activateWindow();
    m_logsUI->refresh();
}

void MainWindow::showAboutUsWidget()
{
    m_aboutUs->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            m_aboutUs->size(),
            qApp->desktop()->availableGeometry()
        ));
    m_aboutUs->show();
    m_aboutUs->activateWindow();
}
