QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += "../mythread.h" \
    gridmanager.h
SOURCES +=  tst_tests.cpp \
    gridmanager.cpp

DISTFILES +=
