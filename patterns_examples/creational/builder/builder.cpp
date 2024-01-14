#include "builder.h"
#include "extra.h"

#include <QDebug>

namespace NBuilder {

Builder::Builder() : IPattern(PatternsDefs::PATTERN_BUILDER)
{
}

void Builder::operator()(const uint32_t initValue) const {
    qInfo() << "=====";

    NBuilder::BaseBuilder* builder = new NBuilder::BaseBuilder();

    builder->printText();
    builder->buildIsMax()->buildMode();
    builder->printText();

    delete builder;

    qInfo() << "=====";
}

void Builder::work(const uint32_t initValue) const
{
    qInfo() << "=====";

    NBuilder::BaseBuilder* builder = new NBuilder::BaseBuilder();

    builder->printText();
    builder->buildIsMax()->buildMode();
    builder->printText();

    delete builder;

    qInfo() << "=====";
}

}
