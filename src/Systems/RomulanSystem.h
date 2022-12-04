#ifndef ROMULAN_SYSTEM_H
#define ROMULAN_SYSTEM_H

#include "../Basedefines.h"
#include "../BaseClass/Entity.h"
#include "../BaseClass/ISystem.h"
#include "../BaseClass/Scene.h"
#include "../Utilities/MathUtils.h"
#include "../Components/Component.h"
#include "../Components/ShipRegistry.h"
#include "../Components/Position.h"
#include "../Utilities/MathUtils.h"

namespace BA_Engine
{

    /// <summary>
    /// Manages and controls all logic for the Romulan faction
    /// </summary>
    class RomulanSystem : public ISystem 
    {

    public:

        RomulanSystem(Scene& pGameScene)
            : mGameScene(pGameScene)
        {

        }

        ~RomulanSystem()
        {

        }

        // Simple logic get closer when not in rage, fire when in range
        // Cloaking be damned, FILL POWER!!!
        void run(const float pElapsedTime)
        {
            
            //Find the Enterprise And Romulans
            
            std::vector<Entity> ships = mGameScene.getEntitiesWith<ShipRegistry>();

            Entity enterprise;
            std::vector<Entity> romulans;

            for (Entity ship : ships)
            {
                ShipRegistry* shipReg = ship.getComponent<ShipRegistry>();
                if (shipReg->mRace == "Federation")
                {
                    enterprise = ship;
                }
                else
                {
                    romulans.push_back(ship);
                }
            }

            Position* entPos = enterprise.getComponent<Position>();

            for (Entity romulanShip : romulans)
            {
                ShipRegistry*   myReg  = romulanShip.getComponent<ShipRegistry>();
                Disruptor*      mydisr = romulanShip.getComponent<Disruptor>();
                Position*       myPos  = romulanShip.getComponent<Position>();
                ImpulseEngines* myEng  = romulanShip.getComponent<ImpulseEngines>();

                float distance = MathUtils::getDistance(
                    entPos->mX, entPos->mY,
                    myPos->mX,  myPos->mY
                );

                if (distance < mydisr->mMaxRange)
                {
                    //Fire when in range

                    Health* entHealth = enterprise.getComponent<Health>();
                    entHealth->mHitBy.push_back(std::pair<std::string, float>(
                        myReg->mName, mydisr->mDamage
                    ));
                }
                else
                {
                    //Lerp Closer to the Enterprise
                    myPos->mX = 
                        MathUtils::lerp(myPos->mX, entPos->mX, (myEng->mSpeed * 0.01f));
                    myPos->mY = 
                        MathUtils::lerp(myPos->mY, entPos->mY, (myEng->mSpeed * 0.01f));
                }

            }
            
        }

    private:

        Scene& mGameScene;
    };

}

#endif //ROMULAN_SYSTEM_H