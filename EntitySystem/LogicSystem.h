#ifndef LOGICSYSTEM_H
#define LOGICSYSTEM_H

#include <QtGlobal>
#include <QMetaType>

class EntitySystem;

class LogicSystem
{
private:
    bool m_enabled;

    EntitySystem *m_entitySystem;

public:
    LogicSystem();
    virtual ~LogicSystem(){}

    void enable();
    void disable();
    bool isEnabled();

    void setEntitySystem(EntitySystem *par_entitySystem);
    EntitySystem* getEntitySystem();

    virtual void initialize() {}

    virtual void injectUpdate(const qint64 &par_timeSinceLastUpdate) = 0;

protected:
    virtual void enabled() {}
    virtual void disabled() {}
};

#endif
