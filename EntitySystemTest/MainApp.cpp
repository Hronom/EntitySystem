#include "MainApp.h"

#include <QTimerEvent>

#include "EntitysIterator.h"

#include "ComClientConnection.h"
#include "HealthCom.h"
#include "PositionCom.h"

#include "TestSys1.h"
#include "TestSys2.h"
#include "TestSys3.h"

MainApp::MainApp(QObject *par_parent): QObject(par_parent)
{
    startTimer(0);
}

MainApp::~MainApp()
{
    // Remove
}

void MainApp::timerEvent(QTimerEvent *par_event)
{
    killTimer(par_event->timerId());

    EntitySystem *entitySystem;
    entitySystem = new EntitySystem();

    {
        {
            Entity *entity;
            entity = entitySystem->getEntity("Entity1");

            ComClientConnection *comConnection = new ComClientConnection();
            entity->addComponent(comConnection);

            HealthCom *healthCom = new HealthCom();
            entity->addComponent(healthCom);

            PositionCom *positionCom = new PositionCom();
            entity->addComponent(positionCom);
        }
        {
            Entity *entity;
            entity = entitySystem->getEntity("Entity2");

            ComClientConnection *comConnection = new ComClientConnection();
            entity->addComponent(comConnection);

            HealthCom *healthCom = new HealthCom();
            entity->addComponent(healthCom);

            PositionCom *positionCom = new PositionCom();
            entity->addComponent(positionCom);
        }
        {
            TestSys1 *testSys1;
            testSys1 = new TestSys1();
            entitySystem->setLogicSystem(testSys1);
            testSys1->enable();
        }
        {
            TestSys2 *testSys2;
            testSys2 = new TestSys2();
            entitySystem->setLogicSystem(testSys2);
            testSys2->enable();
        }
        {
            TestSys3 *testSys3;
            testSys3 = new TestSys3();
            entitySystem->setLogicSystem(testSys3);
            testSys3->enable();
        }
    }

    entitySystem->initialize();

    qDebug()<<"Begin test";
    entitySystem->injectUpdate(0);
    qDebug()<<"End test";

    delete entitySystem;
}
