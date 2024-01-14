#include <QDebug>

#include <memory>

#include "starters/creational/startersingleton.h"
#include "starters/creational/starterprototype.h"
#include "starters/creational/starterbuilder.h"
#include "patterns_examples/ipattern.h"

int main()
{
    qDebug() << "Start MAIN";

    /// Select pattern (Starter...) --- USE Factory Method Pattern
    const std::unique_ptr<IStarter> starter { new StarterBuilder() };
    /// Get pattern
    const std::unique_ptr<IPattern> pattern { starter->getPattern() };
    /// Business logic
    pattern->work();

    qDebug() << "Finish MAIN";
    return 0;
}
