QT -= gui
QT += concurrent

TARGET = EntitySystem
TEMPLATE = lib
CONFIG += staticlib c++11

HEADERS += \
    Entity.h \
    TypeInfoUtils.h \
    EntityObserver.h \
    World.h \
    Manager.h \
    EntitySystem.h \
    EntityManager.h \
    Bag.h \
    BagIterator.h \
    BitSet.h

SOURCES += \
    Entity.cpp \
    World.cpp \
    Manager.cpp \
    EntitySystem.cpp \
    EntityManager.cpp \
    Bag.cpp \
    BagIterator.cpp \
    TypeInfoUtils.cpp \
    BitSet.cpp
