#include "decorator.h"
#include "decorator_private.h"


namespace NDecorator {

Decorator::Decorator() : IPattern(PatternsDefs::PATTERN_DECORATOR) {
    qInfo() << "Create decorator\n===\n DECORATOR \n===\n";
}

Decorator::~Decorator()
{
    qInfo() << "\n===\nDestroy decorator";
}

void Decorator::work(const uint32_t _initVal) const
{
    const auto decorator = std::make_unique<NDecorator::DecoratorPrivate>(_initVal);
    /// decorator->...;
}

}
