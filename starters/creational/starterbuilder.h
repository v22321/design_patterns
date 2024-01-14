#ifndef STARTERBUILDER_H
#define STARTERBUILDER_H

#include "../istarter.h"
#include "../../patterns_examples/creational/builder/builder.h"

class StarterBuilder : public IStarter
{
public:
    std::unique_ptr<IPattern> getPattern() const
    {
        return std::make_unique<NBuilder::Builder>();
    }
};

#endif // STARTERBUILDER_H
