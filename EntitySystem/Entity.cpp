#include "Entity.h"

Entity::Entity(QString par_name, QHash<int, QList<Entity *> *> *par_nodes)
{
    m_name = par_name;
    m_nodes = par_nodes;
}

Entity::~Entity()
{
    int entityMask;
    entityMask = m_bitMask.getMask();

    QHash<int, QList<Entity*>*>::Iterator iter;
    iter = m_nodes->begin();
    while(iter != m_nodes->end())
    {
        if(BitMask::contains(iter.key(), entityMask))
        {
            QList<Entity*> *node;
            node = iter.value();
            node->removeOne(this);
        }

        ++iter;
    }
}

QString Entity::getName() const
{
    return m_name;
}

int Entity::getMask() const
{
    return m_bitMask.getMask();
}

void Entity::addEntityToNodes(const int &par_entityMaskOld, const int &par_entityMaskNew)
{
    QHash<int, QList<Entity*>*>::Iterator iter;
    iter = m_nodes->begin();
    while(iter != m_nodes->end())
    {
        if(!BitMask::contains(iter.key(), par_entityMaskOld) && BitMask::contains(iter.key(), par_entityMaskNew))
        {
            QList<Entity*> *node;
            node = iter.value();
            node->append(this);
        }

        ++iter;
    }
}

void Entity::removeEntityFromNodes(const int &par_entityMaskOld, const int &par_entityMaskNew)
{
    QHash<int, QList<Entity*>*>::Iterator iter;
    iter = m_nodes->begin();
    while(iter != m_nodes->end())
    {
        int nodeMask;
        nodeMask = iter.key();
        if(BitMask::contains(nodeMask, par_entityMaskOld) && ! BitMask::contains(nodeMask, par_entityMaskNew))
        {
            QList<Entity*> *node;
            node = iter.value();
            node->removeOne(this);
        }

        ++iter;
    }
}
