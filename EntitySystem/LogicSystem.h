#ifndef LOGICSYSTEM_H
#define LOGICSYSTEM_H

#include <QtGlobal>
#include <QMetaType>

class EntitySystem;

class LogicSystem
{
private:
    EntitySystem *m_entitySystem;

public:
    virtual ~LogicSystem(){}

    void setEntitySystem(EntitySystem *par_entitySystem);
    EntitySystem* getEntitySystem();

    virtual void addedToEntitySystem(){}

    virtual void injectUpdate(const qint64 &par_timeSinceLastUpdate) = 0;
};

#endif
