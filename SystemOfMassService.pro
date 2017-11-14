TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    device.cpp \
    buffer.cpp \
    bid.cpp \
    source.cpp

HEADERS += \
    device.h \
    buffer.h \
    bid.h \
    enums.h \
    defaultoptions.h \
    source.h
