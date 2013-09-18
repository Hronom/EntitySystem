#ifndef ENTITYSYSTEM_H
#define ENTITYSYSTEM_H

#include "Entity.h"
#include "IComponent.h"
#include "LogicSystem.h"

#include <QString>
#include <QHash>
#include <QDebug>

typedef QList<Entity*> const* Entitys;

class EntitySystem
{
private:
    bool m_stopUpdate;

    ////////////////////////////////////////////////////////////////////////////
    // entity name - entity
    QHash<QString, Entity*> m_entitys;

    ////////////////////////////////////////////////////////////////////////////
    // node mask - entitys in node
    QHash<int, QList<Entity*>*> *m_nodes;

    ////////////////////////////////////////////////////////////////////////////
    // Logic system type id - logic system
    QHash<int, LogicSystem*> m_logicSystems; // For fast lookup
    QList<LogicSystem*> m_logicSystemsOrdered; // To iterate in insert order

public:
    EntitySystem();
    virtual ~EntitySystem();

    ////////////////////////////////////////////////////////////////////////////
    // Entitys methods
    Entity* getEntity(const QString &par_name);
    QList<Entity*> getAllEntitys();
    void removeEntity(const QString &par_name);

    Entitys createEntitysGroup(const BitMask &par_mask);

    ////////////////////////////////////////////////////////////////////////////
    // LogicSystems methods
    template<typename T>
    void setLogicSystem(T *par_logicSystem)
    {
        int logicSystemType;
        logicSystemType = qMetaTypeId<T>();

        par_logicSystem->setEntitySystem(this);

        m_logicSystems.insert(logicSystemType, par_logicSystem);
        m_logicSystemsOrdered.append(par_logicSystem);

        par_logicSystem->addedToEntitySystem();

        stopUpdate();
    }

    template<typename T>
    T* getLogicSystem()
    {
        int logicSystemType;
        logicSystemType = qMetaTypeId<T>();

        T* logicSystem;
        logicSystem = static_cast<T*>(m_logicSystems.value(logicSystemType));

        return logicSystem;
    }

    QList<LogicSystem*> getAllLogicSystems();

    template<typename T>
    void removeLogicSystem()
    {
        int logicSystemType;
        logicSystemType = qMetaTypeId<T>();

        T *logicSystem;
        logicSystem = static_cast<T*>(m_logicSystems.take(logicSystemType));
        m_logicSystemsOrdered.removeAll(logicSystem);

        stopUpdate();
    }

    template<typename T>
    T* takeLogicSystem()
    {
        int logicSystemType;
        logicSystemType = qMetaTypeId<T>();

        T *logicSystem;
        logicSystem = static_cast<T*>(m_logicSystems.take(logicSystemType));
        m_logicSystemsOrdered.removeAll(logicSystem);

        stopUpdate();

        return logicSystem;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Update methods
    void injectUpdate(const float& par_timeSinceLastUpdate);
    void stopUpdate();

    ////////////////////////////////////////////////////////////////////////////
    // Debug methods
    void printInfo();
};

#endif
