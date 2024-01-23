TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
    patterns_examples/creational/builder/builder.cpp \
    patterns_examples/creational/factory_method/factorymethod.cpp \
    patterns_examples/creational/prototype/prototype.cpp \
    main.cpp \
    patterns_examples/creational/singleton/singleton.cpp \
    patterns_examples/structural/decorator/decorator.cpp \
    patterns_examples/structural/decorator/decorator_private.cpp

HEADERS += \
    patterns_examples/creational/builder/builder.h \
    patterns_examples/creational/builder/extra.h \
    patterns_examples/creational/factory_method/extra.h \
    patterns_examples/ipattern.h \
    patterns_examples/structural/decorator/decorator.h \
    patterns_examples/structural/decorator/decorator_private.h \
    starters/istarter.h \
    patternsdefs.h \
    patterns_examples/creational/prototype/extra.h \
    patterns_examples/creational/prototype/prototype.h \
    patterns_examples/creational/factory_method/factorymethod.h \
    patterns_examples/creational/singleton/singleton.h \
    patterns_examples/creational/singleton/singleton_extra.h \
    starters/creational/starterbuilder.h \
    starters/creational/starterprototype.h \
    starters/creational/startersingleton.h \
    starters/structural/starterdecorator.h
