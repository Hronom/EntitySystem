QT -= gui
QT += concurrent

TARGET = EntitySystem
TEMPLATE = lib
CONFIG += staticlib c++11

HEADERS += \
    Entity.h \
    Entity.inl \
    TypeInfoUtils.h \
    EntityObserver.h \
    World.h \
    Manager.h \
    EntitySystem.h \
    EntityManager.h \
    Bag.h \
    BagIterator.h \
    BitSet.h \
    BitSet.inl \
    ComponentManager.h \
    ComponentManager.inl \
    Component.h

SOURCES += \
    Entity.cpp \
    World.cpp \
    Manager.cpp \
    EntitySystem.cpp \
    EntityManager.cpp \
    Bag.cpp \
    BagIterator.cpp \
    TypeInfoUtils.cpp \
    BitSet.cpp \
    ComponentManager.cpp \
    EntityObserver.cpp \
    Component.cpp
