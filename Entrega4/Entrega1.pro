QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

SOURCES += \
    areadesenho.cpp \
    camera/Camera.cpp \
    cohen_sutherland.cpp \
    displayfile.cpp \
    main.cpp \
    mainwindow.cpp \
    core/matriz.cpp \
    core/matriz3d.cpp \
    mundo/objeto3d.cpp \
    objloader.cpp \
    mundo/poligono.cpp \
    core/ponto.cpp \
    core/Vetor.cpp \
    mundo/reta.cpp \
    tinyobjloader_impl.cpp

HEADERS += \
    areadesenho.h \
    core/Vetor.h \
    cohen_sutherland.h \
    core/coordenadas.h \
    camera/Camera.h \
    displayfile.h \
    mainwindow.h \
    core/matriz.h \
    core/matriz3d.h \
    mundo/objeto.h \
    mundo/objeto3d.h \
    objloader.h \
    mundo/poligono.h \
    core/ponto.h \
    mundo/reta.h \
    core/tipos.h \
    libs/tiny_obj_loader.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/libs
	       $$PWD/core
	       $$PWD/camera
	       $$PWD/mundo
	       $$PWD/projecao
	       $$PWD/viewport
	       $$PWD/renderizador

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
