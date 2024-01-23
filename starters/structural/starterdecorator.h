#ifndef STARTERDECORATOR_H
#define STARTERDECORATOR_H

#include "../istarter.h"
#include "../../patterns_examples/structural/decorator/decorator.h"

class StarterDecorator : public IStarter
{
public:
    std::unique_ptr<IPattern> getPattern() const override
    {
        return std::make_unique<NDecorator::Decorator>();
    }
};

#endif // STARTERDECORATOR_H
