#ifndef ISTARTER_H
#define ISTARTER_H

#include <memory>
#include "patterns_examples/ipattern.h"

/// Factory method - Create custom pattern
class IStarter {
public:
    virtual ~IStarter() {}
    virtual std::unique_ptr<IPattern> getPattern() const = 0;
};

#endif // ISTARTER_H
