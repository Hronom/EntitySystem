#ifndef ENTITY_INL
#define ENTITY_INL

#include "ComponentManager.h"

template<typename T>
void Entity::addComponent(T *par_component)
{
    m_componentManager->addComponent(this, par_component);
}

template<typename T>
bool Entity::hasComponent() const
{
    return m_componentManager->hasComponent<T>(this);
}

template<typename T>
T* Entity::getComponent() const
{
    return m_componentManager->getComponent<T>(this);
}

template<typename T>
void Entity::removeComponent()
{
    m_componentManager->removeComponent<T>(this);
}

template<typename T>
T* Entity::takeComponent()
{
    return m_componentManager->takeComponent<T>(this);
}

#endif
