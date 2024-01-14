#ifndef DECORATOR_H
#define DECORATOR_H

#include "../../ipattern.h"

namespace NDecorator
{

class Decorator : public IPattern
{
public:
    Decorator();

    void work(const uint32_t _initVal) const;
};

}

#endif // DECORATOR_H
