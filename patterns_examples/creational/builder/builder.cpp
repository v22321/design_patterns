#include "builder.h"
#include "builder_private.h"

#include <QDebug>

namespace NBuilder {

Builder::Builder() : IPattern(PatternsDefs::PATTERN_BUILDER)
{
    qInfo() << "Create builder\n===\n BUILDER \n===\n";
}

Builder::~Builder()
{
    qInfo() << "\n===\nDestroy decorator";
}

void Builder::work(const uint32_t _initValue) const
{
    auto testBuilder {
                     [](const std::shared_ptr<NBuilder::IBuilder>& _builder) -> void {
            qInfo() << "1) Init product";
            _builder->printData();

            _builder->buildIsMax()->buildMode();

            qInfo() << "2) Build product";
            // Print modified data
            _builder->printData();

            qInfo() << "3) Fin";
        }
    };


    const std::vector<std::shared_ptr<IBuilder>> builderList {
        { std::make_shared<NBuilder::BaseBuilder>(_initValue) },
        { std::make_shared<NBuilder::UltraBuilder>(100) }
    };

    std::for_each(builderList.cbegin(), builderList.cend(), testBuilder);
}

}
