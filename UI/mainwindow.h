#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>

// Subwidgets
#include "UI/controls.h"
#include "UI/drone.h"
#include "UI/laser.h"
#include "UI/systems.h"

// Menu widgets
#include "UI/aboutus.h"
#include "UI/rs232_ui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setupSubWidgets();

private slots:
    void showConnectWidget();
    void showSimulationWidget();
    void showLogWidget();
    void showAboutUsWidget();


private:
    Ui::MainWindow *ui;

    Controls *m_uiControls;
    Drone *m_uiDrone;
    Laser *m_uiLaser;
    Systems *m_uiSystems;

    AboutUs *m_aboutUs;
    Rs232_ui *m_rs232;
};

#endif // MAINWINDOW_H
