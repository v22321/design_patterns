#include "singleton.h"
#include "singleton_private.h"

#include <QDebug>

namespace NSingleton {

Singleton::Singleton() : IPattern(PatternsDefs::PATTERN_SINGLETON)
{
    qInfo() << "Create singleton\n===\n SINGLETON \n===\n";
}

Singleton::~Singleton()
{
    qInfo() << "\n===\nDestroy singleton";
}

void Singleton::work(const uint32_t _initVal) const
{
    BaseSingleton::instance()->init(_initVal);

    bool stopIt {false};
    uint8_t limit {100};
    while (!stopIt && --limit) {
        qInfo() << "Using singleton";
        stopIt = BaseSingleton::instance()->work();
        qInfo() << "Enough?" << stopIt;
    }

    if (!limit)
        qInfo() << "> Limit reached <";
}

}
