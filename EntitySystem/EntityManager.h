#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Manager.h"

#include <QList>
#include <QQueue>

class Entity;

class EntityManager: public Manager
{
private:
    ////////////////////////////////////////////////////////////////////////////
    // Entitys storages
    QList<Entity*> m_entitys;
    ////////////////////////////////////////////////////////////////////////////

    QQueue<Entity*> m_freeEntitys;

public:
    explicit EntityManager();
    ~EntityManager();

    void setStartBagSize(int par_size);

    ////////////////////////////////////////////////////////////////////////////
    // Entitys methods
    Entity* createEntity();
    Entity* getEntity(const int &par_id);

    void deleted(Entity *par_entity);
    ////////////////////////////////////////////////////////////////////////////
};

#endif
