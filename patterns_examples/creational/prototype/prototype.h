#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "../../ipattern.h"

namespace NPrototype {
///
/// \brief The Prototype class Позволяет копировать объекты, не вдаваясь в подробности реализации
///
class Prototype : public IPattern
{
public:
    Prototype();
    ~Prototype();
    void work(const uint32_t _initVal) const override;
};

}
#endif // PROTOTYPE_H
