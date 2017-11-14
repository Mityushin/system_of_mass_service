TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    device.cpp \
    buffer.cpp \
    bid.cpp

HEADERS += \
    smooptions.h \
    device.h \
    buffer.h \
    bid.h \
    enums.h
