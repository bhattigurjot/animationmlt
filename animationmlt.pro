#-------------------------------------------------
#
# Project created for mlt-animation examples
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = animationmlt
CONFIG   += console
CONFIG   -= app_bundle

win32 {
    INCLUDEPATH += /usr/include/mlt++ /usr/include/mlt
    LIBS += -Llib -lmlt++ -lmlt
} else {
    CONFIG += link_pkgconfig
    PKGCONFIG += mlt++
}

TEMPLATE = app

SOURCES += main.cpp animationmlt.cpp

HEADERS += \
    animationmlt.h
