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
    EntitysIterator.cpp

HEADERS += \
    Entity.h \
    IComponent.h \
    BitMask.h \
    EntitySystem.h \
    LogicSystem.h \
    EntitysIterator.h
