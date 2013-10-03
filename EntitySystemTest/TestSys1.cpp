#include "TestSys1.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"
#include "BitMask.h"

#include "ComClientConnection.h"
#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

TestSys1::TestSys1()
{
}

BitMask TestSys1::getInterest()
{
    BitMask bitMask;
    bitMask.add<ComClientConnection>();
    bitMask.add<HealthCom>();
    bitMask.add<PositionCom>();
    return bitMask;
}

void TestSys1::initialize()
{
}

void TestSys1::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_entitys.count() != 2)
        qDebug()<<"TestSys1"<<"Wrong count of entitys.";

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
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
