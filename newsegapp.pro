#-------------------------------------------------
#
# Project created by QtCreator 2021-04-20T23:38:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newsegapp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    graphicsview.cpp

HEADERS  += widget.h \
    graphicsview.h

FORMS    += widget.ui

RESOURCES += \
    image.qrc

INCLUDEPATH += D:\opencv\install\install\include\
D:\opencv\opencv\build\include\opencv2\
D:\opencv\opencv\build\bin\

LIBS +=D:\opencv\install\install\x86\mingw\bin\libopencv_*.dll
-lopencv_world320
-lopencv_world320d
