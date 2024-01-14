#ifndef EXTRA_H
#define EXTRA_H

#include <QDebug>

namespace NPrototype {

enum Proto_type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class BasePrototype {
protected:
    QString m_name;
    float m_field;

public:
    BasePrototype() : m_name(QString()), m_field(0) {}
    explicit BasePrototype(const QString& _name) : m_name(_name), m_field(0) {}
    BasePrototype(const QString& _name, const float _field) : m_name(_name), m_field(_field) {}
    ~BasePrototype() = default;
    virtual BasePrototype* clone() = 0;
    void setField(const float _field)
    {
        m_field = _field;
        qInfo() << "Default prototype set field: " << m_field;
    }

    float getField() const { qInfo() << "GET >"; return m_field; }

    // BasePrototype(const BasePrototype& _other) // = default;
    // {
    //     qInfo() << "COPY COPY";
    // }
};

class Product : public BasePrototype {
private:
    float m_prodField;

public:
    Product(const QString& _name, const float _field) :
        BasePrototype(_name, _field) {}
    BasePrototype* clone() {
        return new Product(*this);
    }

    // Product(const Product& _other) = default;
    // {
    //     qInfo() << "COPY >>>";
    //     setField(_other.getField());
    // }

};

}
#endif // EXTRA_H
