#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include "Manager.h"
#include "Component.h"
#include "Bag.h"
#include "BitSet.h"

class Entity;

class ComponentManager: public Manager
{
private:
    Bag<Bag<Component*>*> m_componentsByType;

public:
    explicit ComponentManager();
    ~ComponentManager();

    template<typename T>
    void addComponent(Entity *par_entity, T *par_component);

    template<typename T>
    bool hasComponent(const Entity *const par_entity) const;

    template<typename T>
    T* getComponent(const Entity *const par_entity) const;

    template<typename T>
    void removeComponent(Entity *par_entity);

    template<typename T>
    T* takeComponent(Entity *par_entity);

    void deleted(Entity *par_entity);
};

#include "ComponentManager.inl"

#endif
