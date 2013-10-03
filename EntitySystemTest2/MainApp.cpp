#include "MainApp.h"

#include <QTimerEvent>

#include "World.h"
#include "Entity.h"
#include "BagIterator.h"

#include "HealthCom.h"
#include "PositionCom.h"

#include "TestSys1.h"
#include "TestSys2.h"
#include "TestSys3.h"

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



    QElapsedTimer timer;



    qDebug()<<"Create entitys begin...";
    timer.restart();
    {
        for(int i=0; i<999999; ++i)
        {
            Entity *entity;
            entity = world->createEntity();

            HealthCom *healthCom = new HealthCom();
            entity->addComponent(healthCom);

            PositionCom *positionCom = new PositionCom();
            entity->addComponent(positionCom);
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
