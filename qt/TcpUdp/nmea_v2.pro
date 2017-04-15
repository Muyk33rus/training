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
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES +=

INCLUDEPATH += C:\opencv\build\install\include
LIBS += -LC:\opencv\build\install\x86\mingw\bin\
-lopencv_core320 \
-lopencv_imgproc320 \
-lopencv_highgui320 \
-lopencv_flann320 \
-lopencv_calib3d320 \
#-lopencv_contrib320 \
-lopencv_features2d320 \
#-lopencv_gpu320 \
#-lopencv_legacy320 \
-lopencv_ml320 \
#-lopencv_nonfree320 \
-lopencv_objdetect320 \
#-lopencv_ocl320 \
-lopencv_photo320 \
-lopencv_stitching320  \
-lopencv_superres320 \
-lopencv_video320  \
-lopencv_videostab320
