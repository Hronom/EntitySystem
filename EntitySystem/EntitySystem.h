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
    bool m_passive;

protected:
    World *m_world;
    Bag<Entity*> m_entitys;

public:
    EntitySystem();
    virtual ~EntitySystem() {}

    void setWorld(World *par_world);
    void setStartBagSize(int par_size);
    virtual BitMask getInterest() = 0;

    virtual void initialize() {}

    void setPassive(bool par_passive);
    bool isPassive();
    virtual bool checkProcessing();

    virtual void injectUpdate(const qint64 &par_timeSinceLastUpdate) = 0;

    virtual void added(Entity *par_entity);
    virtual void changed(Entity *par_entity);
    virtual void deleted(Entity *par_entity);
};

#endif
