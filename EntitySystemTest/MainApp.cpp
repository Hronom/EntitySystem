#include "MainApp.h"

#include <QTimerEvent>

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"
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

    World *world;
    world = new World();

    {
        {
            TestSys1 *testSys1;
            testSys1 = new TestSys1();
            world->setSystem(testSys1);
        }
        {
            TestSys2 *testSys2;
            testSys2 = new TestSys2();
            world->setSystem(testSys2);
        }
        {
            TestSys3 *testSys3;
            testSys3 = new TestSys3();
            world->setSystem(testSys3);
        }
    }

    {
        {
            Entity *entity;
            entity = world->createEntity();

            ComClientConnection *comConnection = new ComClientConnection();
            entity->addComponent(comConnection);

            HealthCom *healthCom = new HealthCom();
            entity->addComponent(healthCom);

            PositionCom *positionCom = new PositionCom();
            entity->addComponent(positionCom);
        }
        {
            Entity *entity;
            entity = world->createEntity();

            ComClientConnection *comConnection = new ComClientConnection();
            entity->addComponent(comConnection);

            HealthCom *healthCom = new HealthCom();
            entity->addComponent(healthCom);

            PositionCom *positionCom = new PositionCom();
            entity->addComponent(positionCom);
        }
    }

    world->initializeAll();

    qDebug()<<"Begin test";
    world->injectUpdate(0);
    qDebug()<<"End test";

    delete world;
}
