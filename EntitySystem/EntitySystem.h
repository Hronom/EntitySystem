#ifndef ENTITYSYSTEM_H
#define ENTITYSYSTEM_H

#include "EntityObserver.h"
#include "BitMask.h"
#include "Bag.h"

#include <QtGlobal>

class World;

class EntitySystem: public EntityObserver
{
private:
    BitMask m_entitysMask;
    bool m_passive;

protected:
    World *m_world;
    Bag<Entity*> m_entitys;

public:
    explicit EntitySystem();
    virtual ~EntitySystem() {}

protected:
    template <typename T>
    void addComponentType()
    {
        int componentType = TypeInfoUtils::getComponentTypeID<T>();
        m_entitysMask.add(componentType);
    }

public:
    void setWorld(World *par_world);
    void setStartBagSize(int par_size);

    virtual void initialize() {}

    void setPassive(bool par_passive);
    bool isPassive();
    virtual bool checkProcessing();

    virtual void injectUpdate(const qint64 &par_timeSinceLastUpdate) = 0;

    virtual void check(Entity *par_entity);

protected:
    virtual void added(Entity *par_entity);
    virtual void changed(Entity *par_entity);
    virtual void deleted(Entity *par_entity);
};

#endif
