#ifndef ENTERPRISE_SYSTEM_H
#define ENTERPRISE_SYSTEM_H

#include "../BaseClass/ISystem.h"
#include "../Utilities/ConsoleUtils.h"
#include "../Utilities/MathUtils.h"

#include "../Components/Component.h"
#include "../Components/ShipRegistry.h"
#include "../Components/Position.h"

namespace BA_Engine
{

    /// <summary>
    /// 
    /// </summary>
    class EnterpriseSystem : public ISystem
    {

    public:

        EnterpriseSystem(Scene& pGameScene)
            : mGameScene(pGameScene)
        {

        }

        ~EnterpriseSystem()
        {

        }

        struct Target
        {
            ShipRegistry* mReg;
            Position*     mPos;
            Health*       mHel;

            float mDistance = 0.0f;
        };

        /// <summary>
        /// Cycle through and get the players command
        /// </summary>
        void run(float pElapsedTime)
        {
            //Find ships
            std::vector<Entity> ships = mGameScene.getEntitiesWith<ShipRegistry>();

            Entity enterprise;
            std::vector<Target> romulans;

            for (Entity ship : ships)
            {
                ShipRegistry* shipReg = ship.getComponent<ShipRegistry>();
                if (shipReg->mRace == "Federation")
                {
                    enterprise = ship;
                }
                else
                {
                    Target romTarg;
                    romTarg.mReg = ship.getComponent<ShipRegistry>();
                    romTarg.mPos = ship.getComponent<Position>();
                    romTarg.mHel = ship.getComponent<Health>();

                    romulans.push_back(romTarg);
                }
            }

            // Display player hit if any

            Health* entHeal = enterprise.getComponent<Health>();

            if (entHeal->mHitBy.size() > 0)
            {
                printMessage("Were hit!");
                printMessage("");

                for (auto pairHit : entHeal->mHitBy)
                {
                    printMessage(
                        ("Disruptor damage from " + pairHit.first + " for " + 
                            std::to_string(pairHit.second)).c_str()
                    );

                    entHeal->mHealth -= pairHit.second;
                    entHeal->mHealth = (entHeal->mHealth < 0) ? 0 : entHeal->mHealth;
                }

                entHeal->mHitBy.clear();

                if (entHeal->mHealth > 0)
                {
                    printMessage("Ships haul integrity down to " + std::to_string(entHeal->mHealth) + " percent!")
                }
                else
                {
                    //Game Over
                }


            }

            //Player picks target
            
            Position* entPos = enterprise.getComponent<Position>();

            std::vector<std::string> options;

            /// Gather details
            for (Target romulan : romulans)
            {
                romulan.mDistance = MathUtils::getDistance(
                    entPos->mX, entPos->mY,
                    romulan.mPos->mX, romulan.mPos->mY
                );

                options.push_back(romulan.mReg->mName);
            }



            //Lerp To get closer
            //Allow option to fire when in range
        }


    private:

        Scene& mGameScene;
    };

}

#endif //ENTERPRISE_SYSTEM_H