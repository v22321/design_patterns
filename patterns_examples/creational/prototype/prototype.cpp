#include "prototype.h"
#include "extra.h"

#include <QDebug>

namespace NPrototype {

Prototype::Prototype() : IPattern(PatternsDefs::PATTERN_PROTOTYPE)
{
    qInfo() << "Create prototype\n===\n PROTOTYPE \n===\n";
}

Prototype::~Prototype()
{
    qInfo() << "\n===\nDestroy prototype";
}

void Prototype::work(const uint32_t _initVal) const
{
    const std::unique_ptr<const NPrototype::Product> product { std::make_unique<NPrototype::Product>("Proto", 1.1) };
    qInfo() << "--- Product --- ";
    product->printInfo();

    NPrototype::AbstractPrototype* const productClone = product->clone();
    qInfo() << "--- Product clone --- ";
    productClone->printInfo();

    productClone->setField(2.2);

    qInfo() << "|Prototype|";
    product->printInfo();
    qInfo() << "|Product|";
    productClone->printInfo();

    delete productClone;
}

}
