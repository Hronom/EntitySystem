QT       -= gui
QT += concurrent

TARGET = EntitySystem
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += \
    Entity.cpp \
    BitMask.cpp \
    EntitySystem.cpp \
    LogicSystem.cpp \
    EntitysIterator.cpp \
    TypeInfoUtils.cpp

HEADERS += \
    Entity.h \
    BitMask.h \
    EntitySystem.h \
    LogicSystem.h \
    EntitysIterator.h \
    TypeInfoUtils.h
