#ifndef CLASS_H
#define CLASS_H

#include "../BaseClass/GameController.h"

#include "../BaseClass/Scene.h"
#include "../BaseClass/Entity.h"

namespace BA_Engine
{

    #define kNumberOfAttackers 3

    /// <summary>
    /// The no win scenario
    /// </summary>
    class KobayashiMaruControler : public GameController
    {

    public:

        KobayashiMaruControler();
        ~KobayashiMaruControler();

        /// <summary>
        /// 
        /// </summary>
        void setup();

        /// <summary>
        /// 
        /// </summary>
        void start();

        /// <summary>
        /// 
        /// </summary>
        void update(const float pElapsedTime);


        /// <summary>
        /// 
        /// </summary>
        void shutdown();

    private:

        Scene mScene;
        Entity mPlayer;

    };

}

#endif //CLASS_H