#ifndef COMPONENTMANAGER_INL
#define COMPONENTMANAGER_INL

#include "Entity.h"

template<typename T>
void ComponentManager::addComponent(Entity *par_entity, T *par_component)
{
    int componentType;
    componentType = TypeInfoUtils::getComponentTypeID<T>();
    par_entity->m_componentsMask.set(componentType);

    Bag<Component*> *components;
    components = m_componentsByType.get(componentType);

    if(components == 0)
    {
        components = new Bag<Component*>();
        m_componentsByType.set(componentType, components);
    }

    components->set(par_entity->m_id, par_component);
}

template<typename T>
bool ComponentManager::hasComponent(const Entity *const par_entity) const
{
    int componentType;
    componentType = TypeInfoUtils::getComponentTypeID<T>();

    Bag<Component*> *components;
    components = m_componentsByType.get(componentType);

    if(components == 0)
        return false;

    if(components->get(par_entity->m_id) != 0)
        return true;
    else
        return false;
}

template<typename T>
T* ComponentManager::getComponent(const Entity *const par_entity) const
{
    int componentType;
    componentType = TypeInfoUtils::getComponentTypeID<T>();

    Bag<Component*> *components;
    components = m_componentsByType.get(componentType);

    if(components == 0)
        return 0;

    Component *component;
    component = components->get(par_entity->m_id);

    if(component != 0)
        return static_cast<T*>(component);
    else
        return 0;
}

template<typename T>
void ComponentManager::removeComponent(Entity *par_entity)
{
    int componentType;
    componentType = TypeInfoUtils::getComponentTypeID<T>();
    par_entity->m_componentsMask.clear(componentType);

    Bag<Component*> *components;
    components = m_componentsByType.get(componentType);

    if(components == 0)
        return;

    components->remove(par_entity->m_id);
}

template<typename T>
T* ComponentManager::takeComponent(Entity *par_entity)
{
    int componentType;
    componentType = TypeInfoUtils::getComponentTypeID<T>();
    par_entity->m_componentsMask.clear(componentType);

    Bag<Component*> *components;
    components = m_componentsByType.get(componentType);

    if(components == 0)
        return 0;

    Component *component;
    component = components->take(par_entity->m_id);

    if(component == 0)
        return 0;

    T* componentConverted;
    componentConverted = static_cast<T*>(component);

    return componentConverted;
}

#endif
