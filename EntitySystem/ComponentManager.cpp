#include "ComponentManager.h"

#include <QDebug>

ComponentManager::ComponentManager()
{
    qDebug()<<"Creating ComponentManager";
}

ComponentManager::~ComponentManager()
{
    qDebug()<<"Destroying ComponentManager";

    for(int i = 0; i < m_componentsByType.count(); ++i)
    {
        Bag<Component*> *components;
        components = m_componentsByType.get(i);

        if(components != 0)
            delete components;
    }
}

void ComponentManager::deleted(Entity *par_entity)
{
    int i;
    i = par_entity->m_componentsMask.nextSet(0);
    while(i != -1)
    {
        Bag<Component*> *components;
        components = m_componentsByType.get(i);

        if(components != 0)
            components->remove(par_entity->m_id);

        i = par_entity->m_componentsMask.nextSet(i+1);
    }
}
