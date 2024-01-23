#ifndef BUILDER_PRIVATE_H
#define BUILDER_PRIVATE_H

#include <QString>
#include <QDebug>

namespace NBuilder {

class Product {

public:
    explicit Product(const uint32_t _initValue) : m_value(_initValue),
        m_mode("-"), m_size(0), m_isMax(false) {}

    void setMode(const QString& _mode) { if (m_mode != _mode) m_mode = _mode; }
    void setSize(const uint32_t _size) { if (m_size != _size) m_size = _size; }
    void setIsMax(const bool _isMax)   { if (m_isMax != _isMax) m_isMax = _isMax; }

    void printInfo() const {
        qInfo() << "\n=== PRODUCT INFO ===";

        qInfo() << "> VALUE: " << m_value;
        qInfo() << "MODE: " << m_mode;
        qInfo() << "SIZE: " << m_size;
        qInfo() << "IS_MAX: " << m_isMax;

        qInfo() << "=== PRODUCT INFO ===\n";
    }

private:
    QString m_mode;
    uint32_t m_size;
    bool m_isMax;

    uint32_t m_value;
};

class IBuilder : public std::enable_shared_from_this<IBuilder> {
protected:
    std::unique_ptr<Product> m_prod;
public:
    virtual std::shared_ptr<IBuilder> buildMode() = 0;
    virtual std::shared_ptr<IBuilder> buildSize() = 0;
    virtual std::shared_ptr<IBuilder> buildIsMax() = 0;

    virtual void printData() const = 0;
};

class BaseBuilder : public IBuilder {
public:
    BaseBuilder(const uint32_t _initValue) {
        m_prod = std::make_unique<Product>(_initValue);
    }

    void printData() const override {
        if (!m_prod) return;

        m_prod->printInfo();
    }

    std::shared_ptr<IBuilder> buildMode() override {
        if (m_prod)
            m_prod->setMode("BASE_MODE");

        return shared_from_this();
    }
    std::shared_ptr<IBuilder> buildSize() override {
        if (m_prod)
            m_prod->setSize(777);

        return shared_from_this();
    }
    std::shared_ptr<IBuilder> buildIsMax() override {
        if (m_prod)
            m_prod->setIsMax(true);

        return shared_from_this();
    }
};

class UltraBuilder : public IBuilder {
public:
    UltraBuilder(const uint32_t _initValue) {
        m_prod = std::make_unique<Product>(_initValue);
    }

    void printData() const override {
        if (!m_prod) return;

        m_prod->printInfo();
    }

    std::shared_ptr<IBuilder> buildMode() override {
        if (m_prod)
            m_prod->setMode("ULTRA_MODE");

        return shared_from_this();
    }
    std::shared_ptr<IBuilder> buildSize() override {
        if (m_prod)
            m_prod->setSize(1'000'000);

        return shared_from_this();
    }
    std::shared_ptr<IBuilder> buildIsMax() override {
        if (m_prod)
            m_prod->setIsMax(true);

        return shared_from_this();
    }
};

}
#endif // BUILDER_PRIVATE_H
