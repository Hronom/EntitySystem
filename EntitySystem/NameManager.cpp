#include "NameManager.h"

#include "World.h"
#include "Entity.h"

#include <QDebug>

NameManager::NameManager()
{
    qDebug()<<"Creating NameManager";
}

NameManager::~NameManager()
{
    qDebug()<<"Destroying NameManager";
}

bool NameManager::setEntityName(Entity *par_entity, const QString &par_name)
{
    if(!m_entitys.contains(par_name))
    {
        m_entitys.insert(par_name, par_entity);
        return true;
    }
    else
        return false;
}

Entity* NameManager::getEntity(const QString &par_name)
{
    return m_entitys.value(par_name); // TODO can be returned 0
}

void NameManager::deleted(Entity *par_entity)
{
    QString name;
    name = m_entitys.key(par_entity);

    m_entitys.remove(name);
}
