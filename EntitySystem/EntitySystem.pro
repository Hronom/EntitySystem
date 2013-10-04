QT -= gui
QT += concurrent

TARGET = EntitySystem
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += \
    Entity.cpp \
    BitMask.cpp \
    World.cpp \
    Manager.cpp \
    EntitySystem.cpp \
    EntityManager.cpp \
    Bag.cpp \
    BagIterator.cpp \
    TypeInfoUtils.cpp

HEADERS += \
    Entity.h \
    BitMask.h \
    TypeInfoUtils.h \
    EntityObserver.h \
    World.h \
    Manager.h \
    EntitySystem.h \
    EntityManager.h \
    Bag.h \
    BagIterator.h
