#include "ComponentManager.h"

#include <QDebug>

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
    qDebug()<<"Destroying ComponentManager";
}
