QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FinalCodewidget.cpp \
    fcmediator.cpp \
    main.cpp \

HEADERS += \
    FinalCodewidget.h \
    fcmediator.h

FORMS += \
    FinalCodewidget.ui

RESOURCES += \
    ../build-FinalCodeGaming-Desktop_Qt_5_12_11_MinGW_64_bit-Debug/debug/pictures.qrc \


TRANSLATIONS += \
    FinalCodeGaming_zh_TW.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-FinalCodeGaming-Desktop_Qt_5_12_11_MinGW_64_bit-Debug/debug/FinalCodeGaming.exe
