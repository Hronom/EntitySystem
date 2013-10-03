#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Manager.h"

#include <QString>
#include <QList>
#include <QHash>
#include <QQueue>

class World;
class Entity;

class EntityManager: public Manager
{
private:
    World *m_world;

    ////////////////////////////////////////////////////////////////////////////
    // Entitys storages
    QList<Entity*> m_entitys;
    ////////////////////////////////////////////////////////////////////////////

    QQueue<Entity*> m_freeEntitys;

public:
    EntityManager(World *par_world);
    ~EntityManager();

    void setStartBagSize(int par_size);

    ////////////////////////////////////////////////////////////////////////////
    // Entitys methods
    Entity* createEntity();
    Entity* getEntity(const int &par_id);

    void added(Entity *par_entity);
    void changed(Entity *par_entity);
    void deleted(Entity *par_entity);
    ////////////////////////////////////////////////////////////////////////////
};

#endif
