#ifndef DECORATOR_H
#define DECORATOR_H

#include "../../ipattern.h"

namespace NDecorator
{

class Decorator : public IPattern
{
public:
    Decorator();
    ~Decorator();

    void work(const uint32_t _initVal) const override;
};

}

#endif // DECORATOR_H
