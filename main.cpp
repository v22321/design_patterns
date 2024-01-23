#include <QDebug>
#include <vector>

#include "starters/creational/startersingleton.h"
#include "starters/creational/starterprototype.h"
#include "starters/creational/starterbuilder.h"
#include "starters/structural/starterdecorator.h"

#include "patterns_examples/ipattern.h"

int main()
{
    qDebug() << "Start MAIN";

    const uint32_t PATTERN_INDEX {0};
    /// Select pattern (Starter...) --- USE Factory Method Pattern
    std::vector<std::unique_ptr<IStarter>> startersList;
    startersList.emplace_back(new StarterSingleton());      // 0
    startersList.emplace_back(new StarterBuilder());        // 1
    startersList.emplace_back(new StarterPrototype());      // 2
    startersList.emplace_back(new StarterDecorator());      // 3

    if (PATTERN_INDEX >= startersList.size())
        return -1;

    const auto& starter { startersList.at(PATTERN_INDEX) };

    if (!starter)
        return -1;

    /// Get pattern
    const std::unique_ptr<IPattern> pattern { starter->getPattern() };
    if (!pattern)
        return -1;

    /// Business logic
    pattern->work();

    qDebug() << "Finish MAIN";
    return 0;
}
