#ifndef EXTRA_H
#define EXTRA_H

class ITransport {
public:
    virtual void deliver() = 0;
    virtual bool info() = 0;
};

class Car : public ITransport {
    void deliver() override {
        qInfo() << "Deliver by car!";
    }
    bool info() override {
        qInfo() << "CAR INFO";
        return true;
    }

};
class Truck : public ITransport {
    void deliver() override {
        qInfo() << "Deliver by truck!";
    }
    bool info() override {
        qInfo() << "TRUCK INFO";
        return false;
    }
};

class IDeliver {
public:
    virtual ITransport* createTransport() = 0;
};

class CarDeliver : public IDeliver {
    ITransport* createTransport() override {
        return new Car();
    }
};
class TruckDeliver : public IDeliver {
    ITransport* createTransport() override {
        return new Truck();
    }
};

#endif // EXTRA_H
