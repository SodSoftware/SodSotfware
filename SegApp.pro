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

INCLUDEPATH += D:\opencv\install\install\include\
D:\opencv\opencv\build\include\opencv2\
D:\opencv\opencv\build\bin\
D:\Vulkan\1.1.106.0\Include\
D:\ncnn\ncnn-20210322-windows-vs2017\x64\include\ncnn\


LIBS +=
#D:\ncnn\ncnn-20210322-windows-vs2017\x64\lib\
#D:\Vulkan\1.1.106.0\Lib\
D:\opencv\install\install\x86\mingw\bin\libopencv_*.dll
-lopencv_world320
-lopencv_world320d

