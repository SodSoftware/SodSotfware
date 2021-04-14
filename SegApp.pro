#-------------------------------------------------
#
# Project created by QtCreator 2021-03-17T11:47:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SegApp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    graphicsview.cpp

HEADERS  += widget.h \
    graphicsview.h

FORMS    += widget.ui

RESOURCES += \
    image/image.qrc
