#include "MainApp.h"

#include <QTimerEvent>

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "ComHealth.h"
#include "ComPosition.h"

#include "SysTest1.h"
#include "SysTest2.h"
#include "SysTest3.h"

#include <QElapsedTimer>
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
    world->setManagersStartBagSize(999999);
    world->setSystemsStartBagSize(999999);

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
    }



    QElapsedTimer timer;



    qDebug()<<"Create entitys begin...";
    timer.restart();
    {
        for(int i = 0; i < 999999; ++i)
        {
            Entity *entity;
            entity = world->createEntity();

            ComHealth *comHealth = new ComHealth();
            entity->addComponent(comHealth);

            ComPosition *comPosition = new ComPosition();
            entity->addComponent(comPosition);

            entity->update();
        }
    }
    qDebug()<<"Create time:"<<timer.elapsed()<<"milliseconds";

    world->initializeAll();

    for(int i = 1; i < 4; ++i)
    {
        qDebug()<<"Begin update...";

        timer.restart();
        world->injectUpdate(0);

        qDebug()<<"Update time:"<<timer.elapsed()<<"milliseconds";
    }

    delete world;
}
