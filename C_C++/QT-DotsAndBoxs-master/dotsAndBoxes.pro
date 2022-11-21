#-------------------------------------------------
#
# Project created by QtCreator 2018-08-08T13:31:34
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dotsAndBoxes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chessborad.cpp \
    gogal.cpp \
    chessman.cpp \
    xcol.cpp \
    ycol.cpp \
    minmaxai.cpp \
    greedai.cpp \
    gameset.cpp \
    client.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    chessborad.h \
    gogal.h \
    chessman.h \
    xcol.h \
    ycol.h \
    minmaxai.h \
    greedai.h \
    gameset.h \
    client.h \
    server.h

FORMS    += mainwindow.ui \
    gameset.ui

RESOURCES += \
    img.qrc
