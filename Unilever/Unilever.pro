#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T21:55:48
#
#-------------------------------------------------

QT       += core gui sql xlsx

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Unilever
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    dbmanager.cpp \
    parsemanager.cpp \
    employeeswidget.cpp \
    personalcardwidget.cpp \
    positionwidget.cpp \
    listofskillswidget.cpp \
    skillstypewidget.cpp \
    skillslevelwidget.cpp \
    skillswidget.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    constants.h \
    dbmanager.h \
    parsemanager.h \
    employeeswidget.h \
    personalcardwidget.h \
    positionwidget.h \
    listofskillswidget.h \
    skillstypewidget.h \
    skillslevelwidget.h \
    skillswidget.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    employeeswidget.ui \
    personalcardwidget.ui \
    positionwidget.ui \
    listofskillswidget.ui \
    skillstypewidget.ui \
    skillslevelwidget.ui \
    skillswidget.ui

RESOURCES += \
    unileverres.qrc

CONFIG -= app_bundle
CONFIG += c++11
