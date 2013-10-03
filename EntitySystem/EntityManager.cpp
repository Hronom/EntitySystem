#include "EntityManager.h"

#include "World.h"
#include "Entity.h"

#include <QDebug>

EntityManager::EntityManager(World *par_world)
{
    m_world = par_world;
}

EntityManager::~EntityManager()
{
    qDebug()<<"Destroying EntityManager";
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
        m_entitys.replace(entity->getID(), entity);
    }
    else
    {
        entity = new Entity(m_world, m_entitys.size());
        m_entitys.append(entity);
    }

    return entity;
}

Entity* EntityManager::getEntity(const int &par_id)
{
    if(par_id < m_entitys.size())
    {
        Entity *entity;
        entity = m_entitys.at(par_id);
        return entity; // TODO can be returned 0
    }
    else
        return 0;
}

void EntityManager::added(Entity *par_entity)
{

}

void EntityManager::changed(Entity *par_entity)
{

}

void EntityManager::deleted(Entity *par_entity)
{
    int entityID;
    entityID = par_entity->getID();

    if(entityID < m_entitys.size())
    {
        if(m_entitys.at(entityID) != 0)
        {
            m_entitys.replace(entityID, 0);
            m_freeEntitys.enqueue(par_entity);
        }
    }
}
