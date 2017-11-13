TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    simpleapplication.cpp \
    device.cpp \
    buffer.cpp

HEADERS += \
    simpleapplication.h \
    smooptions.h \
    device.h \
    buffer.h
