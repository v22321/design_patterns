#ifndef BUILDER_H
#define BUILDER_H

#include <QtCore>
#include "../../ipattern.h"

namespace NBuilder
{

class Builder : public IPattern
{
public:
    Builder();
    void operator()(const uint32_t initValue) const override;
    void work(const uint32_t initValue) const override;
};

}

#endif // BUILDER_H
