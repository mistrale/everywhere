#-------------------------------------------------
#
# Project created by QtCreator 2015-12-13T21:35:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
                                        uitools

TARGET = Everywhere
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connection.cpp \
    registration.cpp \
    everywherewindow.cpp

HEADERS  += mainwindow.h \
    connection.h \
    registration.h \
    everywherewindow.h

FORMS    += mainwindow.ui \
    connection.ui \
    registration.ui \
    everywherewindow.ui

RESOURCES += \
    resources.qrc
