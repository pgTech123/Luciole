#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMessageBox>

// Subwidgets
#include "UI/controls.h"
#include "UI/drone.h"
#include "UI/laser.h"
#include "UI/systems.h"
#include "UI/battery.h"
#include "UI/supplycontrol.h"

// Menu widgets
#include "UI/aboutus.h"
#include "UI/rs232_ui.h"
#include "UI/simulationdialog.h"
#include "UI/logdialog.h"

// Other
#include "logs.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void emergency(QByteArray);

private:
    void setupSubWidgets();

private slots:
    void showConnectWidget();
    void showResetDialog();
    void showSimulationWidget();
    void showLogWidget();
    void showAboutUsWidget();

private:
    Ui::MainWindow *ui;

    Battery *m_uiBattery;
    Controls *m_uiControls;
    Drone *m_uiDrone;
    Laser *m_uiLaser;
    Systems *m_uiSystems;
    SupplyControl *m_uiSupplyControl;

    AboutUs *m_aboutUs;
    Rs232_ui *m_rs232;
    SimulationDialog *m_simulation;
    LogDialog *m_logsUI;

    Logs *m_logs;
};

#endif // MAINWINDOW_H
