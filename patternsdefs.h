#ifndef PATTERNSDEFS_H
#define PATTERNSDEFS_H

#include <QHash>
#include <QString>

namespace PatternsDefs {

enum PatternsEnum : uint8_t {
    PATTERN_ABSTRACT_METHOD = 0,
    PATTERN_ABSTRACT_FACTORY,
    PATTERN_BUILDER,
    PATTERN_PROTOTYPE,
    PATTERN_SINGLETON
};

static const QHash<PatternsEnum, QString> patternNames {
    { PATTERN_ABSTRACT_METHOD , "Abstract method" },
    { PATTERN_ABSTRACT_FACTORY , "Abstract factory" },
    { PATTERN_BUILDER , "Builder" },
    { PATTERN_PROTOTYPE , "Prototype" },
    { PATTERN_SINGLETON , "Singleton" }
};

}

#endif // PATTERNSDEFS_H
