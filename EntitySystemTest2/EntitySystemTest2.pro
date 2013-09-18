QT       += core

QT       -= gui

TARGET = EntitySystemTest2
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    MainApp.cpp \
    TestSys1.cpp \
    TestSys2.cpp \
    TestSys3.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EntitySystem/release/ -lEntitySystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EntitySystem/debug/ -lEntitySystem
else:unix: LIBS += -L$$OUT_PWD/../EntitySystem/ -lEntitySystem

INCLUDEPATH += $$PWD/../EntitySystem
DEPENDPATH += $$PWD/../EntitySystem

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EntitySystem/release/libEntitySystem.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EntitySystem/debug/libEntitySystem.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../EntitySystem/libEntitySystem.a

HEADERS += \
    PositionCom.h \
    MainApp.h \
    HealthCom.h \
    TestSys1.h \
    TestSys2.h \
    TestSys3.h
