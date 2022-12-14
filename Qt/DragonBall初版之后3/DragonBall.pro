QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big
QT+=multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background_dialogue.cpp \
    bula_dialogue.cpp \
    clabel.cpp \
    huawindow.cpp \
    loginon.cpp \
    main.cpp \
    mainwindow.cpp \
    renwu_dialogue.cpp \
    saiya_dialogue.cpp \
    saiyawinner.cpp

HEADERS += \
    background_dialogue.h \
    bula_dialogue.h \
    clabel.h \
    huawindow.h \
    loginon.h \
    mainwindow.h \
    renwu_dialogue.h \
    saiya_dialogue.h \
    saiyawinner.h

FORMS += \
    background_dialogue.ui \
    bula_dialogue.ui \
    huawindow.ui \
    loginon.ui \
    mainwindow.ui \
    renwu_dialogue.ui \
    saiya_dialogue.ui \
    saiyawinner.ui

TRANSLATIONS += \
    DragonBall_zh_CN.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    music.qrc
