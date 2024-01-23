#ifndef IPATTERN_H
#define IPATTERN_H

#include "../patternsdefs.h"

#include <QDebug>

class IPattern {

protected:
    const PatternsDefs::PatternsEnum PATTERN_CODE;
public:
    IPattern(const PatternsDefs::PatternsEnum _patternCode)
        : PATTERN_CODE(_patternCode)
    {
        if (PatternsDefs::patternNames.size() < PATTERN_CODE)
        {
            qWarning() << "Wrong pattern code";
            return;
        }
        qInfo() << "Init base pattern \' "\
                << PatternsDefs::patternNames[PATTERN_CODE]
                << " \'";
    }
    /// Deprecated
    virtual void operator()(const uint32_t _initVal) const {}
    virtual void work(const uint32_t _initVal = 0) const = 0;
    virtual ~IPattern()
    {
        qInfo() << "Destroy base pattern \' "\
                << PatternsDefs::patternNames[PATTERN_CODE]
                << " \'";
    }
};

#endif // IPATTERN_H
