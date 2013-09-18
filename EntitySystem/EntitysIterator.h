#ifndef ENTITYSITERATOR_H
#define ENTITYSITERATOR_H

#include "EntitySystem.h"

class EntitysIterator
{
private:
    Entitys m_entitys;
    int m_lastSize;
    QList<Entity*>::ConstIterator m_iter;

public:
    EntitysIterator();
    ~EntitysIterator();

    void setContainer(Entitys par_entitys);

    bool hasNext();

    Entity* next();
};

#endif
