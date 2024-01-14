#include "singleton.h"
#include "singleton_extra.h"
#include "../../../patternsdefs.h"

#include <QDebug>

namespace NSingleton {

Singleton::Singleton() : IPattern(PatternsDefs::PATTERN_SINGLETON)
{
}

Singleton::~Singleton()
{
}

void Singleton::operator()(const uint32_t _initVal) const
{
    qInfo() << "=====";
    BaseSingleton::instance()->work();
    qInfo() << "=====";
}

void Singleton::work(const uint32_t _initVal) const
{
    qInfo() << "=====";
    qInfo() << "Init value: " << _initVal;
    BaseSingleton::instance()->work();
    BaseSingleton::instance()->work();
    qInfo() << "=====";
}

}
