#ifndef EXTRA_H
#define EXTRA_H

#include <QString>
#include <QDebug>

namespace NBuilder {

class Product {

public:
    Product() : m_mode("-"), m_size(0), m_isMax(false) {}

    void setMode(const QString& _mode) { m_mode = _mode; }
    void setSize(const uint32_t _size) { m_size = _size; }
    void setIsMax(const bool _isMax) { m_isMax = _isMax; }

    void printInfo() const {
        qInfo() << "INFO >>>";
        qInfo() << "MODE: " << m_mode;
        qInfo() << "SIZE: " << m_size;
        qInfo() << "ISMAX: " << m_isMax;
        qInfo() << "INFO <<<";
    }

private:
    QString m_mode;
    uint32_t m_size;
    bool m_isMax;
};

class IBuilder {
public:
    virtual IBuilder* buildMode() = 0;
    virtual IBuilder* buildSize() = 0;
    virtual IBuilder* buildIsMax() = 0;

    virtual void printText() const = 0;
};

class BaseBuilder : public IBuilder {
    Product* _prod {nullptr};
public:
    BaseBuilder() {
        _prod = new Product();
    }
    ~BaseBuilder() {
        delete _prod;
    }

    void printText() const override {
        if (_prod == nullptr) return;

        _prod->printInfo();
    }

    IBuilder* buildMode() override {
        if (_prod == nullptr) return this;

        _prod->setMode("Test");

        return this;
    }
    IBuilder* buildSize() override {
        if (_prod == nullptr) return this;

        _prod->setSize(100);

        return this;
    }
    IBuilder* buildIsMax() override {
        if (_prod == nullptr) return this;

        _prod->setIsMax(true);

        return this;
    }
};

class UltraBuilder : public IBuilder {
    Product* m_prod;
public:
    UltraBuilder() { m_prod = new Product(); }
    ~UltraBuilder() { delete m_prod; }

};

}
#endif // EXTRA_H
