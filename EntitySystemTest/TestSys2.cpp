#include "TestSys2.h"

#include "EntitysIterator.h"
#include "BitMask.h"

#include "ComClientConnection.h"
#include "HealthCom.h"
#include "PositionCom.h"

#include <QDebug>

#include <QElapsedTimer>

TestSys2::TestSys2()
{
}

void TestSys2::addedToEntitySystem()
{
    BitMask bitMask;
    bitMask.add<ComClientConnection>();
    bitMask.add<PositionCom>();

    m_node = getEntitySystem()->createEntitysGroup(bitMask);
}

void TestSys2::injectUpdate(const qint64 &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    if(m_node->count() != 2)
        qDebug()<<"TestSys2"<<"Wrong count of entitys.";

    EntitysIterator iter;
    iter.setContainer(m_node);
    while(iter.hasNext())
    {
        Entity *entity;
        entity = iter.next();

        ComClientConnection *comConnection;
        comConnection = entity->getComponent<ComClientConnection>();
        if(comConnection == NULL)
            qDebug()<<"TestSys2"<<"ComConnection is NULL";

        HealthCom *healthCom;
        healthCom = entity->getComponent<HealthCom>();
        if(healthCom != NULL)
            qDebug()<<"TestSys2"<<"HealthCom not NULL";

        PositionCom *positionCom;
        positionCom = entity->getComponent<PositionCom>();
        if(positionCom == NULL)
            qDebug()<<"TestSys2"<<"PositionCom is NULL";

        HealthCom *newHealthCom = new HealthCom();
        entity->addComponent(newHealthCom);
    }    
}
