#ifndef HEALTH_H
#define HEALTH_H

#include "../PrecompiledHeader.h"
#include "../BaseClass/IComponent.h"

namespace BA_Engine
{

    /// <summary>
    /// Life value of the Entity
    /// </summary>
    class Health : public IComponent
    {
    public:

        float mHealth;

        Health() = default;
        Health(const Health&) = default;
        Health(float pHealth)
            : mHealth(pHealth)
        {}

    };

}

#endif //HEALTH_H