#include "decorator_private.h"

#include <QDebug>

namespace NDecorator {

/// Components
class IComponent {
public:
    virtual ~IComponent() {}
    virtual void useComponent() const = 0;
};

class FirstComponent : public IComponent {
public:
    void useComponent() const override {
        qInfo() << "First component is working";
    }
};
class SecondComponent : public IComponent {
public:
    void useComponent() const override {
        qInfo() << "Second component work";
    }
};

/// Decorators - add extra logic
class IDecorator : public IComponent {
public:
    const std::shared_ptr<IComponent> currentComponent;
    explicit IDecorator(const std::shared_ptr<IComponent>& _component)
        : currentComponent(_component) {}
    virtual ~IDecorator() {}
};

class FirstDecorator : public IDecorator {
public:
    using IDecorator::IDecorator;
    // explicit FirstDecorator(const std::shared_ptr<IComponent>& _component)
    //     : IDecorator(_component) {}

    void useComponent() const override {
        qInfo() << "Fist decorator is working";
        // ...

        if (currentComponent)
            currentComponent->useComponent();
    }
};
class SecondDecorator : public IDecorator {
public:
    using IDecorator::IDecorator;
    // explicit SecondDecorator(const std::shared_ptr<IComponent>& _component)
    //     : IDecorator(_component) {}

    void useComponent() const override {
        qInfo() << "Second decorator is working";
        // ...

        if (currentComponent)
            currentComponent->useComponent();
    }
};

DecoratorPrivate::DecoratorPrivate(const uint32_t _value)
    : m_value(_value)
{
    /// Create component and some decorators
    const auto comp = std::make_shared<FirstComponent>();
    const auto decor = std::make_shared<FirstDecorator>(comp);
    const auto decor2 = std::make_shared<SecondDecorator>(decor);

    /// Run them all
    decor2->useComponent();
}

}
