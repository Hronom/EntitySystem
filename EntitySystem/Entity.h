#ifndef ENTITY_H
#define ENTITY_H

#include "BitSet.h"
#include "TypeInfoUtils.h"
#include "Bag.h"
#include "World.h"

class Entity
{
private:
    World *m_world;

    int m_id;

    BitSet m_componentsMask;
    BitSet m_systemsMask;

    // component type - component
    Bag<void*> m_components;

public:
    explicit Entity(World *par_world, int par_id);
    ~Entity();

    int getID();

    ////////////////////////////////////////////////////////////////////////////
    // Components methods
    BitSet getComponentsMask();

    template<typename T>
    void addComponent(T *par_component)
    {
        int componentType = TypeInfoUtils::getComponentTypeID<T>();
        m_componentsMask.set(componentType);
        m_components.set(componentType, par_component);

        m_world->updateEntity(this);
    }

    template<typename T>
    bool hasComponent() const
    {
        int componentType = TypeInfoUtils::getComponentTypeID<T>();
        if(m_components.contains(componentType))
            return true;
        else
            return false;
    }

    template<typename T>
    T* getComponent() const
    {
        int componentType = TypeInfoUtils::getComponentTypeID<T>();
        if(m_components.contains(componentType))
            return static_cast<T*>(m_components.get(componentType));
        else
            return 0;
    }

    template<typename T>
    void removeComponent()
    {
        int componentType = TypeInfoUtils::getComponentTypeID<T>();
        m_componentsMask.clear(componentType);
        m_components.remove(componentType);

        m_world->updateEntity(this);
    }

    template<typename T>
    T* takeComponent()
    {
        int componentType = TypeInfoUtils::getComponentTypeID<T>();
        m_componentsMask.clear(componentType);

        T* component;
        component = static_cast<T*>(m_components.take(componentType));

        m_world->updateEntity(this);

        return component;
    }
};

#endif
