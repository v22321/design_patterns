#ifndef EXTRA_H
#define EXTRA_H

#include <QDebug>

namespace NPrototype {


class AbstractPrototype {
protected:
    QString m_name;
    float m_field;

    AbstractPrototype(const AbstractPrototype& _other)
        : m_name(_other.m_name), m_field(_other.m_field)
    {
        qInfo() << "Abstract create copy";
    }

public:
    AbstractPrototype() : m_name(QString()), m_field(0) {}
    explicit AbstractPrototype(const QString& _name) : m_name(_name), m_field(0) {}
    AbstractPrototype(const QString& _name, const float _field) : m_name(_name), m_field(_field) {}

    /// Clone prototype !
    virtual AbstractPrototype* clone() const = 0;

    void setField(const float _field)
    {
        if (m_field == _field) return;
        m_field = _field;
    }

    float getField() const { return m_field; }

    virtual void printInfo() const {
        qInfo() << "Info > ";
        qInfo() << "Name: " << m_name;
        qInfo() << "Field: " << m_field;
        qInfo() << "---";
    }
};

class Product : public AbstractPrototype {
private:
    float m_prodField;

public:
    Product(const QString& _name, const float _field) :
        AbstractPrototype(_name, _field) {}

    AbstractPrototype* clone() const override {
        return new Product(*this);
    }

    Product(const Product& _other) : AbstractPrototype(_other), m_prodField(_other.m_prodField)
    {
        qInfo() << "Product create copy";
    }

    void printInfo() const override {
        AbstractPrototype::printInfo();
        qInfo() << "Prod field: " << m_prodField;
        qInfo() << "---\n";
    }

};

}
#endif // EXTRA_H
