#ifndef SINGLETON_H
#define SINGLETON_H

#include "../../ipattern.h"

namespace NSingleton {

class Singleton : public IPattern
{
public:
    Singleton();
    ~Singleton();

    void work(const uint32_t _initVal) const override;
};

}
#endif // SINGLETON_H
