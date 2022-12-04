#ifndef TAG_COMPONENT_H
#define TAG_COMPONENT_H

#include "../PrecompiledHeader.h"
#include "../BaseClass/IComponent.h"

namespace BA_Engine
{

    /// <summary>
    /// Simple Identifier on an Entity
    /// </summary>
    class Tag : public IComponent
    {
    public:

        std::string mTag;

        Tag() = default;
        Tag(const Tag&) = default;
        Tag(std::string pTag)
            : mTag(pTag) {}
    };

}

#endif //TAG_COMPONENT_H