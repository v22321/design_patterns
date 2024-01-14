#include "factorymethod.h"
#include "extra.h"

FactoryMethod::FactoryMethod() {
    qInfo() << "Run factory method";
}

FactoryMethod::~FactoryMethod() {
    qInfo() << "Stop factory method";
}

void FactoryMethod::operator()(const uint32_t initVal) const
{
    qInfo() << "=====";

    IDeliver* deliver;
    switch (initVal)
    {
        case 1:
            deliver =  new TruckDeliver();
            break;
        case 2:
            deliver = new CarDeliver();
            break;
        default:
            qWarning() << "Error. Unknown init value";
            return;
    }
    ITransport* transport = deliver->createTransport();
    if (transport == nullptr) {
        qWarning() << "Can't get transport";
        return;
    }
    transport->deliver();
    bool res = transport->info();
    qInfo() << ">> " << bool(res);

    delete transport;
    delete deliver;
    qInfo() << "=====";
}
