#include "Entity.h"

#include "ComponentManager.h"
#include "NameManager.h"

Entity::Entity(World *par_world, int par_id): m_id(par_id)
{
    m_world = par_world;
    m_componentManager = m_world->getComponentManager();
    m_nameManager = m_world->getNameManager();
}

Entity::~Entity()
{
}

int Entity::getID() const
{
    return m_id;
}

void Entity::setName(const QString &par_name)
{
    m_name = par_name;
    m_nameManager->setEntityName(this, par_name);
}

QString Entity::getName() const
{
    return m_name;
}

void Entity::reset()
{
    m_name = "";
    m_componentsMask.clear();
}

void Entity::update()
{
    m_world->updateEntity(this);
}
