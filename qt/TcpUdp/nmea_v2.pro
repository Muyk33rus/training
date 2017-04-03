#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T08:44:37
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nmea_v2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    crc16.cpp

HEADERS  += mainwindow.h \
    crc16.h

FORMS    += mainwindow.ui

DISTFILES +=
