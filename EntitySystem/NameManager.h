#ifndef NAMEMANAGER_H
#define NAMEMANAGER_H

#include "Manager.h"

#include <QHash>

class Entity;

class NameManager: public Manager
{
private:
    ////////////////////////////////////////////////////////////////////////////
    // Entitys storages
    QHash<QString, Entity*> m_entitys;
    ////////////////////////////////////////////////////////////////////////////

public:
    explicit NameManager();
    ~NameManager();

    ////////////////////////////////////////////////////////////////////////////
    // Entitys methods
    bool setEntityName(Entity *par_entity, const QString &par_name);
    Entity* getEntity(const QString &par_name);

    void deleted(Entity *par_entity);
    ////////////////////////////////////////////////////////////////////////////
};

#endif
