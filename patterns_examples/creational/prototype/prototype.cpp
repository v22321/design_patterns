#include "prototype.h"
#include "extra.h"

#include <QDebug>

namespace NPrototype {

Prototype::Prototype() : IPattern(PatternsDefs::PATTERN_PROTOTYPE)
{
}

void Prototype::operator()(const uint32_t _initVal) const {
    qInfo() << "=====";
    NPrototype::Product* product = new NPrototype::Product("Test", 1.2);
    qInfo() << "Product === " << product->getField();
    NPrototype::BasePrototype *productClone = product->clone();
    qInfo() << "Product clone === " << productClone->getField();
    productClone->setField(11.11);
    qInfo() << "Product === " << product->getField();
    qInfo() << "Product clone === " << productClone->getField();
    delete product;
    delete productClone;
    qInfo() << "=====";
}

void Prototype::work(const uint32_t _initVal) const
{
    qInfo() << "=====";
    NPrototype::Product* product = new NPrototype::Product("Test", 1.2);
    qInfo() << "Product === " << product->getField();
    NPrototype::BasePrototype *productClone = product->clone();
    qInfo() << "Product clone === " << productClone->getField();
    productClone->setField(11.11);
    qInfo() << "Product === " << product->getField();
    qInfo() << "Product clone === " << productClone->getField();
    delete product;
    delete productClone;
    qInfo() << "=====";
}

}
