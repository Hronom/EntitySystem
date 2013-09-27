#include "EntitysIterator.h"

EntitySystem::EntitySystem()
{
    m_stopUpdate = false;
    m_nodes = new QHash<int, QList<Entity*>*>();
}

EntitySystem::~EntitySystem()
{
    qDebug()<<"Destroying EntitySystem";
    delete m_nodes;
}

Entity* EntitySystem::getEntity(const QString &par_name)
{
    Entity *entity;
    entity = m_entitys.value(par_name, 0);

    if(entity != 0)
        return entity;
    else
    {
        entity = new Entity(par_name, m_nodes);
        m_entitys.insert(par_name, entity);
        return entity;
    }
}

QList<Entity*> EntitySystem::getAllEntitys()
{
    return m_entitys.values();
}

void EntitySystem::removeEntity(const QString &par_name)
{
    Entity *entity;
    entity = m_entitys.take(par_name);

    delete entity;
}

Entitys EntitySystem::createEntitysGroup(const BitMask &par_mask)
{
    // Create node
    QList<Entity*> *node;

    int nodeMask;
    nodeMask = par_mask.getMask();

    if(!m_nodes->contains(nodeMask))
    {
        node = new QList<Entity*>();
        m_nodes->insert(nodeMask, node);

        // Fill node by existed entitys
        QHash<QString, Entity*>::Iterator iter;
        iter = m_entitys.begin();
        while(iter != m_entitys.end())
        {
            Entity *entity;
            entity = (*iter);

            int entityMask;
            entityMask = entity->getMask();

            if(BitMask::contains(nodeMask, entityMask))
                node->append(entity);

            ++iter;
        }
    }
    else
    {
        node = m_nodes->value(nodeMask);
    }

    return node;
}

void EntitySystem::initialize()
{
    QList<LogicSystem*>::Iterator iter;
    iter = m_logicSystemsOrdered.begin();
    while(iter != m_logicSystemsOrdered.end())
    {
        (*iter)->initialize();
        ++iter;
    }
}

QList<LogicSystem*> EntitySystem::getAllLogicSystems()
{
    return m_logicSystemsOrdered;
}

void EntitySystem::injectUpdate(const float &par_timeSinceLastUpdate)
{
    m_stopUpdate = false;

    QList<LogicSystem*>::Iterator iter;
    iter = m_logicSystemsOrdered.begin();
    while(iter != m_logicSystemsOrdered.end())
    {
        if(!m_stopUpdate)
        {
            LogicSystem *logicSystem;
            logicSystem = (*iter);
            if(logicSystem->isEnabled())
                logicSystem->injectUpdate(par_timeSinceLastUpdate);

            ++iter;
        }
        else
        {
            break;
        }
    }
}

void EntitySystem::stopUpdate()
{
    m_stopUpdate = true;
}

void EntitySystem::printInfo()
{
    qDebug()<<"--------------------- World::printInfo ---------------------";
    {
        qDebug()<<"--- Enitys:";
        QHash<QString, Entity*>::iterator i = m_entitys.begin();
        while(i != m_entitys.end())
        {
            qDebug()<<"Name:"<<i.value()->getName();
            ++i;
        }
    }
    {
        qDebug()<<"--- Nodes:";
        QHash<int, QList<Entity*>*>::iterator i = m_nodes->begin();
        while(i != m_nodes->end())
        {
            qDebug()<<"Mask:"<<i.key();
            ++i;
        }
    }
    qDebug()<<QString(10, '-');
}
