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
    positionwidget.cpp \
    listofskillswidget.cpp \
    skillstypewidget.cpp \
    skillslevelwidget.cpp \
    skillswidget.cpp \
    qchartviewer.cpp \
    personalcardwidget.cpp \
    xlsemployeelistmodel.cpp


HEADERS  += mainwindow.h \
    aboutdialog.h \
    constants.h \
    dbmanager.h \
    parsemanager.h \
    employeeswidget.h \
    positionwidget.h \
    listofskillswidget.h \
    skillstypewidget.h \
    skillslevelwidget.h \
    skillswidget.h \
    qchartviewer.h \
    personalcardwidget.h \
    xlsemployeelistmodel.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    employeeswidget.ui \
    positionwidget.ui \
    listofskillswidget.ui \
    skillstypewidget.ui \
    skillslevelwidget.ui \
    skillswidget.ui \
    personalcardwidget.ui

RESOURCES += \
    unileverres.qrc

INCLUDEPATH += E:\SekiraRepo\ChartDirector\include

DEFINES += CHARTDIR_HIDE_OBSOLETE

LIBS += E:\SekiraRepo\ChartDirector\lib\chartdir60.lib

CONFIG -= app_bundle
CONFIG += c++11
