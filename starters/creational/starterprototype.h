#ifndef STARTERPROTOTYPE_H
#define STARTERPROTOTYPE_H

#include "../istarter.h"
#include "../../patterns_examples/creational/prototype/prototype.h"

class StarterPrototype : public IStarter
{
public:
    std::unique_ptr<IPattern> getPattern() const override
    {
        return std::make_unique<NPrototype::Prototype>();
    }
};

#endif // STARTERPROTOTYPE_H
