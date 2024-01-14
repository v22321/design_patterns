#ifndef IPATTERN_H
#define IPATTERN_H

#include "cstdint"
#include "../patternsdefs.h"

#include <QDebug>

class IPattern {
    PatternsDefs::PatternsEnum patternCode;
public:
    IPattern(const PatternsDefs::PatternsEnum _patternCode)
        : patternCode(_patternCode)
    {
        qInfo() << "Init base pattern \' "\
                << PatternsDefs::patternNames[patternCode]
                << " \'";
    }
    virtual void operator()(const uint32_t _initVal) const {}
    virtual void work(const uint32_t _initVal = 0) const = 0;
    virtual ~IPattern()
    {
        qInfo() << "Deinit base pattern \' "\
                << PatternsDefs::patternNames[patternCode]
                << " \'";
    }
};

#endif // IPATTERN_H
