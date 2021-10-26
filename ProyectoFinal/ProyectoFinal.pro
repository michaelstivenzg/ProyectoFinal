QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ayuda.cpp \
    bullet.cpp \
    enemies.cpp \
    enemies2.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    municion.cpp \
    player.cpp \
    vida.cpp

HEADERS += \
    ayuda.h \
    bullet.h \
    enemies.h \
    enemies2.h \
    login.h \
    mainwindow.h \
    municion.h \
    player.h \
    vida.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
