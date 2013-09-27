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

void TestSys1::initialize()
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
        if(comConnection == 0)
            qDebug()<<"TestSys1"<<"ComConnection is 0";

        HealthCom *healthCom;
        healthCom = entity->getComponent<HealthCom>();
        if(healthCom == 0)
            qDebug()<<"TestSys1"<<"HealthCom is 0";

        PositionCom *positionCom;
        positionCom = entity->getComponent<PositionCom>();
        if(positionCom == 0)
            qDebug()<<"TestSys1"<<"PositionCom is 0";

        entity->removeComponent<HealthCom>();
    }
}
