QT += core
QT -= gui

TARGET = opencvtest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += C:\opencv\build\install\include
LIBS += -LC:\opencv\build\install\x86\mingw\bin\
-lopencv_core2413 \
-lopencv_imgproc2413 \
-lopencv_highgui2413 \
-lopencv_flann2413 \
-lopencv_calib3d2413 \
-lopencv_contrib2413 \
-lopencv_features2d2413 \
-lopencv_gpu2413 \
-lopencv_legacy2413 \
-lopencv_ml2413 \
-lopencv_nonfree2413 \
-lopencv_objdetect2413 \
-lopencv_ocl2413 \
-lopencv_photo2413 \
-lopencv_stitching2413  \
-lopencv_superres2413 \
-lopencv_video2413  \
-lopencv_videostab2413
