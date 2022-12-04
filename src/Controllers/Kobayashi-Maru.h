#ifndef KOBAYASHI_MARU_CONTROLLER_H
#define KOBAYASHI_MARU_CONTROLLER_H

#include "../BaseClass/GameController.h"

#include "../BaseClass/Scene.h"
#include "../BaseClass/Entity.h"
#include "../Systems/EnterpriseSystem.h"
#include "../Systems/RomulanSystem.h"

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
        /// Create Entities and add their components for the game
        /// </summary>
        void setup();

        /// <summary>
        /// The initial into sequence of the game
        /// </summary>
        void start();

        /// <summary>
        /// Loop on game logic
        /// </summary>
        void update(const float pElapsedTime);

        /// <summary>
        /// Exiting the game
        /// </summary>
        void shutdown();

    private:

        Scene mScene;
        Entity mPlayer;

        EnterpriseSystem* mEntSys;
        RomulanSystem* mRomSys;
    };

}

#endif //KOBAYASHI_MARU_CONTROLLER_H