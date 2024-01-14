#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "cstdint"
#include "../../ipattern.h"

namespace NPrototype {
///
/// \brief The Prototype class Позволяет копировать объекты, не вдаваясь в подробности реализации
///
class Prototype : public IPattern
{
public:
    Prototype();
    void operator()(const uint32_t _initVal) const override;
    void work(const uint32_t _initVal) const override;
};

}
#endif // PROTOTYPE_H
