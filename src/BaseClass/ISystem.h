#ifndef I_SYSTEM_H
#define I_SYSTEM_H

#include "../Basedefines.h"

namespace BA_Engine
{

    /// <summary>
    /// Operates on a given set of Components
    /// </summary>
    class ISystem
    {
    
    public:

        /// <summary>
        /// Perform operations for the given system
        /// </summary>
        virtual void run(const float pElapsedTime) = 0;

    };

}

#endif //I_SYSTEM_H