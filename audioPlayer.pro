#-------------------------------------------------
#
# Project created by QtCreator 2023-08-29T13:51:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = audioPlayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
    src/audio_decode.cpp

HEADERS += \
        include/mainwindow.h \
    include/audio_decode.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    img.qrc

INCLUDEPATH += D:\workdir\qt\myVideoPlayer\include\ffmpeg
INCLUDEPATH += D:\workdir\qt\myVideoPlayer\include\SDL2

LIBS += -LD:\workdir\qt\myVideoPlayer\lib\ffmpeg -lswresample -lavformat -lswscale -lavutil  -lavcodec  -lavdevice -lavfilter
LIBS += -LD:\workdir\qt\myVideoPlayer\lib\SDL2
