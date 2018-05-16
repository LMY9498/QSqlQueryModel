#-------------------------------------------------
#
# Project created by QtCreator 2018-05-14T10:19:11
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = querymodel
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mysqlquerymodel.cpp

HEADERS  += widget.h \
    database.h \
    mysqlquerymodel.h

FORMS    += widget.ui
