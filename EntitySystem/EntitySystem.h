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

    ////////////////////////////////////////////////////////////////////////////
    // node mask - entitys in node
    QHash<int, QList<Entity*>*> *m_nodes;
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Entry name - entry
    QHash<QString, void*> m_boardEntrys;
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Logic system type id - logic system
    QHash<int, LogicSystem*> m_logicSystems; // For fast lookup
    QList<LogicSystem*> m_logicSystemsOrdered; // To iterate in insert order
    ////////////////////////////////////////////////////////////////////////////

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

    ////////////////////////////////////////////////////////////////////////////
    // BlackBoard methods
    template<typename T>
    void addEntry(const QString &par_name, T *par_entry)
    {
        m_boardEntrys.insert(par_name, par_entry);
    }

    template<typename T>
    bool hasEntry(const QString &par_name) const
    {
        if(m_boardEntrys.contains(par_name))
            return true;
        else
            return false;
    }

    template<typename T>
    T* getEntry(const QString &par_name) const
    {
        if(m_boardEntrys.contains(par_name))
            return static_cast<T*>(m_boardEntrys.value(par_name));
        else
            return 0;
    }

    template<typename T>
    void removeEntry(const QString &par_name)
    {
        m_boardEntrys.remove(par_name);
    }

    template<typename T>
    T* takeEntry(const QString &par_name)
    {
        T* component;
        component = static_cast<T*>(m_boardEntrys.take(par_name));

        return component;
    }
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // LogicSystems methods
    void initialize();

    template<typename T>
    void setLogicSystem(T *par_logicSystem)
    {
        int logicSystemType;
        logicSystemType = qMetaTypeId<T>();

        par_logicSystem->setEntitySystem(this);

        m_logicSystems.insert(logicSystemType, par_logicSystem);
        m_logicSystemsOrdered.append(par_logicSystem);

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

        LogicSystem *logicSystem;
        logicSystem = m_logicSystems.take(logicSystemType);
        m_logicSystemsOrdered.removeAll(logicSystem);

        logicSystem->disable();

        stopUpdate();
    }

    template<typename T>
    T* takeLogicSystem()
    {
        int logicSystemType;
        logicSystemType = qMetaTypeId<T>();

        LogicSystem *logicSystem;
        logicSystem = m_logicSystems.take(logicSystemType);
        m_logicSystemsOrdered.removeAll(logicSystem);

        logicSystem->disable();

        T *logicSystemConverted;
        logicSystemConverted = static_cast<T*>(logicSystem);

        stopUpdate();

        return logicSystemConverted;
    }
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Update methods
    void injectUpdate(const float& par_timeSinceLastUpdate);
    void stopUpdate();
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Debug methods
    void printInfo();
    ////////////////////////////////////////////////////////////////////////////
};

#endif
