#include "MainApp.h"

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"
#include "ComClientConnection.h"
#include "ComHealth.h"
#include "ComPosition.h"

#include "SysTest1.h"
#include "SysTest2.h"
#include "SysTest3.h"
#include "SysTest4.h"
#include "SysTest5.h"

#include <QTimerEvent>
#include <QDebug>

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
            SysTest1 *sysTest1;
            sysTest1 = new SysTest1();
            world->setSystem(sysTest1);
        }
        {
            SysTest2 *sysTest2;
            sysTest2 = new SysTest2();
            world->setSystem(sysTest2);
        }
        {
            SysTest3 *sysTest3;
            sysTest3 = new SysTest3();
            world->setSystem(sysTest3);
        }
        {
            SysTest4 *sysTest4;
            sysTest4 = new SysTest4();
            world->setSystem(sysTest4);
        }
        {
            SysTest5 *sysTest5;
            sysTest5 = new SysTest5();
            world->setSystem(sysTest5);
        }
    }

    {
        {
            Entity *entity;
            entity = world->createEntity();

            ComClientConnection *comConnection = new ComClientConnection();
            entity->addComponent(comConnection);

            ComHealth *comHealth = new ComHealth();
            entity->addComponent(comHealth);

            ComPosition *comPosition = new ComPosition();
            entity->addComponent(comPosition);

            entity->update();
        }
        {
            Entity *entity;
            entity = world->createEntity();

            ComClientConnection *comConnection = new ComClientConnection();
            entity->addComponent(comConnection);

            ComHealth *comHealth = new ComHealth();
            entity->addComponent(comHealth);

            ComPosition *comPosition = new ComPosition();
            entity->addComponent(comPosition);

            entity->update();
        }
    }

    world->initializeAll();

    for(int i = 0; i<2; ++i)
    {
        qDebug()<<"Begin test"<<i;
        world->injectUpdate(0);
        qDebug()<<"End test"<<i;
    }

    delete world;
}
