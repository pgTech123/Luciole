#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->gridLayout);

    // Child Widgets
    m_uiControls = new Controls(this);
    m_uiDrone = new Drone(this);
    m_uiLaser = new Laser(this);
    m_uiSystems = new Systems(this);

    // Menu Widgets
    m_aboutUs = new AboutUs();
    m_rs232 = new Rs232_ui();

    // Setup child widgets
    this->setupSubWidgets();

    // Signals
    connect(ui->actionConnect, SIGNAL(triggered(bool)), this, SLOT(showConnectWidget()));
    connect(ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->actionSimulation, SIGNAL(triggered(bool)), this,SLOT(showSimulationWidget()));
    connect(ui->actionLogs, SIGNAL(triggered(bool)), this, SLOT(showLogWidget()));
    connect(ui->actionAbout_us, SIGNAL(triggered(bool)), this, SLOT(showAboutUsWidget()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_aboutUs;
    delete m_rs232;
}

void MainWindow::setupSubWidgets()
{
    ui->verticalLayoutControls->addWidget(m_uiControls);
    ui->verticalLayoutDrone->addWidget(m_uiDrone);
    ui->verticalLayoutLaser->addWidget(m_uiLaser);
    ui->verticalLayoutSystems->addWidget(m_uiSystems);

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

void MainWindow::showSimulationWidget()
{

}

void MainWindow::showLogWidget()
{

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
