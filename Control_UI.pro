#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T16:05:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Control_UI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        UI/mainwindow.cpp \
    UI/alarmelement.cpp \
    UI/systems.cpp \
    UI/controls.cpp \
    UI/laser.cpp \
    UI/drone.cpp \
    UI/valueelement.cpp \
    UI/aboutus.cpp \
    UI/rs232_ui.cpp \
    UI/simulationdialog.cpp \
    UI/logdialog.cpp \
    UI/battery.cpp \
    logs.cpp

HEADERS += \
        UI/mainwindow.h \
    UI/alarmelement.h \
    UI/systems.h \
    UI/controls.h \
    UI/laser.h \
    UI/laser.h \
    UI/drone.h \
    UI/valueelement.h \
    UI/aboutus.h \
    UI/rs232_ui.h \
    UI/simulationdialog.h \
    UI/logdialog.h \
    constants.h \
    UI/battery.h \
    logs.h

FORMS += \
        UI/mainwindow.ui \
    UI/systems.ui \
    UI/controls.ui \
    UI/laser.ui \
    UI/drone.ui \
    UI/aboutus.ui \
    UI/rs232_ui.ui \
    UI/simulationdialog.ui \
    UI/logdialog.ui \
    UI/battery.ui
