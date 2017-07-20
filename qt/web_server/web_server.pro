QT += core network

CONFIG += c++11

TARGET = web_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    qsocketrun.cpp

HEADERS += \
    server.h \
    qsocketrun.h
