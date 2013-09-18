#include "EntitysIterator.h"

EntitysIterator::EntitysIterator()
{
}

EntitysIterator::~EntitysIterator()
{

}

void EntitysIterator::setContainer(Entitys par_entitys)
{
    m_entitys = par_entitys;
    m_lastSize = m_entitys->size();
    m_iter = m_entitys->constBegin();
}

bool EntitysIterator::hasNext()
{
    if(m_entitys->size() != m_lastSize)
    {
        m_lastSize = m_entitys->size();
        m_iter = m_entitys->constBegin();
    }

    if(m_iter != m_entitys->constEnd())
        return true;
    else
        return false;
}

Entity* EntitysIterator::next()
{
    Entity *entity;
    entity = (*m_iter);

    ++m_iter;

    return entity;
}
