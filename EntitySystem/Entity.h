#ifndef ENTITY_H
#define ENTITY_H

#include "World.h"
#include "TypeInfoUtils.h"
#include "BitSet.h"
#include "Bag.h"

class ComponentManager;

class Entity
{
    friend class EntitySystem;
    friend class ComponentManager;
private:
    World *m_world;
    ComponentManager *m_componentManager;

    const int m_id;

    BitSet m_componentsMask;
    BitSet m_systemsMask;

public:
    explicit Entity(World *par_world, int par_id);
    ~Entity();

    int getID() const;

    ////////////////////////////////////////////////////////////////////////////
    // Components methods
    template<typename T>
    void addComponent(T *par_component);

    template<typename T>
    bool hasComponent() const;

    template<typename T>
    T* getComponent() const;

    template<typename T>
    void removeComponent();

    template<typename T>
    T* takeComponent();
    ////////////////////////////////////////////////////////////////////////////
};

#include "Entity.inl"

#endif
