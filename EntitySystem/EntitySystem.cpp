#include "EntitySystem.h"

#include "World.h"
#include "Entity.h"

#include <QtGlobal>
#include <QDebug>

EntitySystem::EntitySystem()
{
    m_enabled = false;
}

void EntitySystem::setWorld(World *par_world)
{
    m_world = par_world;
}

void EntitySystem::setSystemIndex(const int &par_type)
{
    m_systemIndex = par_type;
}

void EntitySystem::reserveEntitysBag(int par_size)
{
    m_entitys.reserve(par_size);
}

void EntitySystem::enable()
{
    enabled();
    m_enabled = true;
}

bool EntitySystem::isEnabled()
{
    return m_enabled;
}

void EntitySystem::disable()
{
    disabled();
    m_enabled = false;
}

void EntitySystem::added(Entity *par_entity)
{
    check(par_entity);
}

void EntitySystem::changed(Entity *par_entity)
{
    check(par_entity);
}

void EntitySystem::deleted(Entity *par_entity)
{
    if(m_entitys.contains(par_entity->m_id))
        removeFromSystem(par_entity);
}

void EntitySystem::disabled(Entity *par_entity)
{
    if(m_entitys.contains(par_entity->m_id))
        removeFromSystem(par_entity);
}

void EntitySystem::enabled(Entity *par_entity)
{
    check(par_entity);
}

void EntitySystem::inserted(Entity *par_entity)
{
    Q_UNUSED(par_entity)
}

void EntitySystem::removed(Entity *par_entity)
{
    Q_UNUSED(par_entity)
}

void EntitySystem::check(Entity *par_entity)
{
    if(m_entitys.contains(par_entity->m_id))
    {
        // Delete if needed
        if(BitSet::contains(m_entitysMask, par_entity->m_componentsMask) == false)
            removeFromSystem(par_entity);
    }
    else
    {
        // Insert if needed
        if(BitSet::contains(m_entitysMask, par_entity->m_componentsMask) == true)
            insertToSystem(par_entity);
    }
}

void EntitySystem::insertToSystem(Entity *par_entity)
{
    m_entitys.set(par_entity->m_id, par_entity);
    inserted(par_entity);
}

void EntitySystem::removeFromSystem(Entity *par_entity)
{
    m_entitys.remove(par_entity->m_id);
    removed(par_entity);
}

