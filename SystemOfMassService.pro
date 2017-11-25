#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graph
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

#TEMPLATE = app
#CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += \
    bid.cpp \
    buffer.cpp \
    device.cpp \
    devicemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    servicemanager.cpp \
    source.cpp \
    sourcemanager.cpp \
    stepwindow.cpp \
    watcher.cpp

HEADERS += \
    bid.h \
    buffer.h \
    defaultoptions.h \
    device.h \
    devicemanager.h \
    enums.h \
    mainwindow.h \
    servicemanager.h \
    source.h \
    sourcemanager.h \
    stepwindow.h \
    watcher.h

FORMS += \
    mainwindow.ui \
    stepwindow.ui

RESOURCES += \
    resources.qrc
