#include "EntityManager.h"

#include "World.h"
#include "Entity.h"

#include <QDebug>

EntityManager::EntityManager()
{
    qDebug()<<"Creating EntityManager";
}

EntityManager::~EntityManager()
{
    qDebug()<<"Destroying EntityManager";

    for(int i = 0; i < m_entitys.count(); ++i)
    {
        Entity *entity;
        entity = m_entitys.take(i);

        if(entity != 0)
            delete entity;
    }

    while(m_freeEntitys.isEmpty() == false)
        delete m_freeEntitys.dequeue();
}

void EntityManager::setStartBagSize(int par_size)
{
    m_entitys.reserve(par_size);
}

Entity* EntityManager::createEntity()
{
    Entity *entity;

    if(!m_freeEntitys.empty())
    {
        entity = m_freeEntitys.dequeue();
        entity->reset();
        m_entitys.set(entity->m_id, entity);
    }
    else
    {
        entity = new Entity(m_world, m_entitys.count());
        m_entitys.set(entity->m_id, entity);
    }

    return entity;
}

Entity* EntityManager::getEntity(const int &par_id)
{
    return m_entitys.get(par_id); // TODO can be returned 0
}

void EntityManager::deleted(Entity *par_entity)
{
    Entity *entity;
    entity = m_entitys.take(par_entity->m_id);

    if(entity != 0)
        m_freeEntitys.enqueue(entity);
}
