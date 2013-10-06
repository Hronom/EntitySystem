#ifndef ENTITYSYSTEM_H
#define ENTITYSYSTEM_H

#include "EntityObserver.h"
#include "BitSet.h"
#include "Bag.h"

class World;
class Entity;

class EntitySystem: public EntityObserver
{
private:
    BitSet m_entitysMask;
    bool m_passive;

protected:
    World *m_world;
    int m_systemIndex;
    Bag<Entity*> m_entitys;

public:
    explicit EntitySystem();
    virtual ~EntitySystem() {}

    void setWorld(World *par_world);
    void setSystemIndex(const int &par_type);
    void reserveEntitysBag(int par_size);

    void setPassive(bool par_passive);
    bool isPassive();

    virtual void initialize() {}

    virtual void injectUpdate(const qint64 &par_timeSinceLastUpdate) = 0;

    void added(Entity *par_entity);
    void changed(Entity *par_entity);
    void deleted(Entity *par_entity);
    void disabled(Entity *par_entity);
    void enabled(Entity *par_entity);

protected:
    template <typename T>
    void addComponentType()
    {
        int componentType = TypeInfoUtils::getComponentTypeID<T>();
        m_entitysMask.set(componentType);
    }

    // Called if the system has received a entity it is interested in, e.g. created or a component was added to it.
    virtual void inserted(Entity *par_entity);

    // Called if a entity was removed from this system, e.g. deleted or had one of it's components removed.
    virtual void removed(Entity *par_entity);

private:
    void check(Entity *par_entity);
    void insertToSystem(Entity *par_entity);
    void removeFromSystem(Entity *par_entity);
};

#endif
