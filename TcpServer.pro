#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T16:08:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tcpserver.cpp \
    socketthread.cpp

HEADERS  += widget.h \
    tcpserver.h \
    socketthread.h

FORMS    += widget.ui


MOC_DIR=temp/moc

RCC_DIR=temp/rcc

UI_DIR=temp/ui

OBJECTS_DIR=temp/obj

DESTDIR=bin

