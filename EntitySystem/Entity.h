#ifndef ENTITY_H
#define ENTITY_H

#include "BitMask.h"
#include "TypeInfoUtils.h"
#include "Bag.h"
#include "World.h"

class Entity
{
private:
    World *m_world;

    int m_id;

    BitMask m_componentsMask;
    BitMask m_systemsMask;

    // component type - component
    Bag<void*> m_components;

public:
    explicit Entity(World *par_world, int par_id);
    ~Entity();

    int getID();

    ////////////////////////////////////////////////////////////////////////////
    // Components methods
    template<typename T>
    void addComponent(T *par_component)
    {
        int entityMaskOld;
        entityMaskOld = m_componentsMask.getMask();

        int componentType = TypeInfoUtils::getTypeID<T>();
        m_componentsMask.add(componentType);
        m_components.set(componentType, par_component);

        int entityMaskNew;
        entityMaskNew = m_componentsMask.getMask();

        m_world->updateEntity(this, entityMaskOld, entityMaskNew);
    }

    template<typename T>
    bool hasComponent() const
    {
        int componentType = TypeInfoUtils::getTypeID<T>();
        if(m_components.contains(componentType))
            return true;
        else
            return false;
    }

    template<typename T>
    T* getComponent() const
    {
        int componentType = TypeInfoUtils::getTypeID<T>();
        if(m_components.contains(componentType))
            return static_cast<T*>(m_components.get(componentType));
        else
            return 0;
    }

    template<typename T>
    void removeComponent()
    {
        int entityMaskOld;
        entityMaskOld = m_componentsMask.getMask();

        int componentType = TypeInfoUtils::getTypeID<T>();
        m_componentsMask.remove(componentType);
        m_components.remove(componentType);

        int entityMaskNew;
        entityMaskNew = m_componentsMask.getMask();

        m_world->updateEntity(this, entityMaskOld, entityMaskNew);
    }

    template<typename T>
    T* takeComponent()
    {
        int entityMaskOld;
        entityMaskOld = m_componentsMask.getMask();

        int componentType = TypeInfoUtils::getTypeID<T>();
        m_componentsMask.remove(componentType);

        T* component;
        component = static_cast<T*>(m_components.take(componentType));

        int entityMaskNew;
        entityMaskNew = m_componentsMask.getMask();

        m_world->updateEntity(this, entityMaskOld, entityMaskNew);

        return component;
    }
};

#endif
