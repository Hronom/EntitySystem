QT += core
QT -= gui

TARGET = EntitySystemTest2
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    MainApp.h \
    ComClientConnection.h \
    ComHealth.h \
    ComPosition.h \
    SysTest1.h \
    SysTest2.h \
    SysTest3.h

SOURCES += main.cpp \
    MainApp.cpp \
    SysTest1.cpp \
    SysTest2.cpp \
    SysTest3.cpp

# EntitySystem
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EntitySystem/release/ -lEntitySystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EntitySystem/debug/ -lEntitySystem
else:unix: LIBS += -L$$OUT_PWD/../EntitySystem/ -lEntitySystem

INCLUDEPATH += $$PWD/../EntitySystem
DEPENDPATH += $$PWD/../EntitySystem

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EntitySystem/release/libEntitySystem.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EntitySystem/debug/libEntitySystem.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../EntitySystem/libEntitySystem.a
