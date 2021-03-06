#include "TypeInfoUtils.h"

#include "BitSet.h"

#include <QtGlobal>
#include <QDebug>

class ManagerX
{
public:
};

class ManagerY
{
public:
};

class SystemX
{
public:
};

class SystemY
{
public:
};

class ComponentX
{
public:
};

class ComponentY
{
public:
};

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug()<<TypeInfoUtils::getManagerTypeID<ManagerX>()<<TypeInfoUtils::getManagerTypeID<ManagerY>();
    qDebug()<<TypeInfoUtils::getSystemTypeID<SystemX>()<<TypeInfoUtils::getSystemTypeID<SystemY>();
    qDebug()<<TypeInfoUtils::getComponentTypeID<ComponentX>()<<TypeInfoUtils::getComponentTypeID<ComponentY>();

    BitSet bits;
    bits.set(1);
    bits.set(62);
    qDebug()<<bits.test(1)
            <<bits.test(62)
            <<bits.test(3);

    return 0;
}
