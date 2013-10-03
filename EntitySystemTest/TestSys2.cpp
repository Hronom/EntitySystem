#include "TestSys2.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"
#include "BitMask.h"

#include "ComClientConnection.h"
#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

#include <QElapsedTimer>

TestSys2::TestSys2()
{
}

BitMask TestSys2::getInterest()
{
    BitMask bitMask;
    bitMask.add<ComClientConnection>();
    bitMask.add<PositionCom>();
    return bitMask;
}

void TestSys2::initialize()
{
}

void TestSys2::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_entitys.count() != 2)
        qDebug()<<"TestSys2"<<"Wrong count of entitys.";

    BagIterator<Entity*> iter;
    iter.setContainer(&m_entitys);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComClientConnection *comConnection;
        comConnection = entity->getComponent<ComClientConnection>();
        if(comConnection == 0)
            qDebug()<<"TestSys2"<<"ComConnection is 0";

        HealthCom *healthCom;
        healthCom = entity->getComponent<HealthCom>();
        if(healthCom != 0)
            qDebug()<<"TestSys2"<<"HealthCom not 0";

        PositionCom *positionCom;
        positionCom = entity->getComponent<PositionCom>();
        if(positionCom == 0)
            qDebug()<<"TestSys2"<<"PositionCom is 0";

        HealthCom *newHealthCom = new HealthCom();
        entity->addComponent(newHealthCom);
    }    
}
