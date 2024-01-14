#include "decorator.h"

namespace NDecorator {

Decorator::Decorator() : IPattern(PatternsDefs::PATTERN_DECORATOR) {}

void Decorator::work(const uint32_t _initVal) const
{
    qInfo() << "===";
    qInfo() << "DECORATOR";
    qInfo() << "===";
}

}
