TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    map.cpp \
    wavefront.cpp \
    moving_rules.cpp \
    node.cpp \
    robot_moving.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wunused

#include(deployment.pri)

HEADERS += \
    map.h \
    position_t.h \
    node.h

