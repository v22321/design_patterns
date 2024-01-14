#ifndef STARTERSINGLETON_H
#define STARTERSINGLETON_H

#include "../istarter.h"
#include "../../patterns_examples/creational/singleton/singleton.h"

class StarterSingleton : public IStarter
{
public:
    std::unique_ptr<IPattern> getPattern() const override {
        return std::make_unique<NSingleton::Singleton>();
    }
};

#endif // STARTERSINGLETON_H
