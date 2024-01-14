#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <QDebug>

class FactoryMethod
{
public:
    FactoryMethod();
    ~FactoryMethod();

    void operator()(const uint32_t initVal) const;
};

#endif // FACTORYMETHOD_H
