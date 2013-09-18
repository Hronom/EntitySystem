#include "TestSys1.h"

#include "EntitysIterator.h"
#include "BitMask.h"

#include "ComClientConnection.h"
#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

TestSys1::TestSys1()
{
}

void TestSys1::addedToEntitySystem()
{
    BitMask bitMask;
    bitMask.add<ComClientConnection>();
    bitMask.add<HealthCom>();
    bitMask.add<PositionCom>();

    m_node = getEntitySystem()->createEntitysGroup(bitMask);
}

void TestSys1::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_node->count() != 2)
        qDebug()<<"TestSys1"<<"Wrong count of entitys.";

    EntitysIterator iter;
    iter.setContainer(m_node);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComClientConnection *comConnection;
        comConnection = entity->getComponent<ComClientConnection>();
        if(comConnection == NULL)
            qDebug()<<"TestSys1"<<"ComConnection is NULL";

        HealthCom *healthCom;
        healthCom = entity->getComponent<HealthCom>();
        if(healthCom == NULL)
            qDebug()<<"TestSys1"<<"HealthCom is NULL";

        PositionCom *positionCom;
        positionCom = entity->getComponent<PositionCom>();
        if(positionCom == NULL)
            qDebug()<<"TestSys1"<<"PositionCom is NULL";

        entity->removeComponent<HealthCom>();
    }
}
