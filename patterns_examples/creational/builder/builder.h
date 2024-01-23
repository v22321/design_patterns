#ifndef BUILDER_H
#define BUILDER_H

#include "../../ipattern.h"

namespace NBuilder
{

class Builder : public IPattern
{
public:
    Builder();
    ~Builder();
    void work(const uint32_t initValue) const override;
};

}

#endif // BUILDER_H
