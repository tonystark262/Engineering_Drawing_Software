#-------------------------------------------------
#
# Project created by QtCreator 2018-03-14T21:54:20
#
#-------------------------------------------------

QT       += core gui opengl

DESTDIR=bin #Target file directory
OBJECTS_DIR=build #Intermediate object files directory
MOC_DIR=generated_files #Intermediate moc files directory

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COP290
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include/qtgui
INCLUDEPATH += $$PWD/include/graphics
INCLUDEPATH += $$PWD/include/glm

SOURCES += \
        src/main.cpp \
        src/qtgui/mainwindow.cpp \
	src/qtgui/dialog3dinput.cpp \
	src/qtgui/object3dfunctionswindow.cpp \
	src/qtgui/translatedialogt.cpp \
	src/qtgui/scaledialog.cpp \
	src/qtgui/rotatedialog.cpp \ 
	src/qtgui/reflectdialog.cpp \
	src/qtgui/projectiondialog.cpp \
	src/qtgui/dialogorthoinput.cpp \
	src/qtgui/orthofunctionsdialog.cpp \
	src/graphics/display.cpp \
        src/graphics/object2D.cpp \
        src/graphics/object3D.cpp \
        src/graphics/orthographic.cpp \
        src/graphics/point.cpp

HEADERS += \
        include/qtgui/mainwindow.h \
	include/qtgui/dialog3dinput.h \
	include/qtgui/object3dfunctionswindow.h \
	include/qtgui/translatedialogt.h \
	include/qtgui/scaledialog.h \
	include/qtgui/rotatedialog.h \
	include/qtgui/reflectdialog.h \
	include/qtgui/projectiondialog.h\
	include/qtgui/dialogorthoinput.h \
	include/qtgui/orthofunctionsdialog.h \
	include/graphics/display.h \
	include/graphics/object2D.h \
	include/graphics/object3D.h \
	include/graphics/orthographic.h \
	include/graphics/point.h

SUBDIRS += \
    COP290.pro

Release:DESTDIR = build
Release:OBJECTS_DIR = build/.obj
Release:MOC_DIR = build/.moc
Release:RCC_DIR = build/.rcc


CONFIG+=c++11

unix|win32: LIBS += -lGLU
unix|win32: LIBS += -lGL
unix|win32: LIBS += -lglut
