/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

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

            std::string getStatus()
            {
                return
                    mReg->mName
                    + " - Hull: " + std::to_string(mHel->mHealth)
                    + " - Dist: " + std::to_string(mDistance)
                ;
            }
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

            if (romulans.size() == 0)
            {
                //YOU WIN WHAT!!
                return;
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
                    printMessage("Ships hull integrity down to " + std::to_string(entHeal->mHealth) + " percent!")
                }
                else
                {
                    //Game Over
                    return;
                }
            }

            //Player picks target
            
            Position* entPos = enterprise.getComponent<Position>();

            std::vector<std::pair<std::string, int>> options;

            /// Gather details
            int targetCount = 0;
            for (Target& romulan : romulans)
            {
                romulan.mDistance = MathUtils::getDistance(
                    entPos->mX, entPos->mY,
                    romulan.mPos->mX, romulan.mPos->mY
                );

                options.push_back(
                    std::pair<std::string, int>( romulan.getStatus(), targetCount++ )
                );
            }

            int targetNum = ConsoleUtils::printAndGetOption("Target sir?", options);

            Target primeTarget = romulans[targetNum];

            options.clear();

            Phaser* phasers         = enterprise.getComponent<Phaser>();
            PhotonTorpedo* torpedos = enterprise.getComponent<PhotonTorpedo>();

            if (primeTarget.mDistance >= 5)// TODO: Magic numbers!! EEEEEKKKKK
            {
                options.push_back(std::pair < std::string, int>("Close the gap!", 0));
            }

            //Allow option to fire when in range

            if (primeTarget.mDistance < phasers->mMaxRange)
            {
                options.push_back(std::pair < std::string, int >("Fire phasers!", 1));
            }
            
            if (primeTarget.mDistance < torpedos->mMaxRange)
            {
                options.push_back(std::pair < std::string, int >("Fire photon torpedo!", 2));
            }

            if (primeTarget.mDistance < phasers->mMaxRange && primeTarget.mDistance < torpedos->mMaxRange)
            {
                options.push_back(std::pair < std::string, int >("Fire all weapons!", 3));
            }

            int actionNum = ConsoleUtils::printAndGetOption("Action sir?", options);

            ShipRegistry* entReg  = enterprise.getComponent<ShipRegistry>();
            ImpulseEngines* myEng = enterprise.getComponent<ImpulseEngines>();

            switch (actionNum)
            {

            case 0:

                //Lerp To get closer, I want to hit them with my sword!

                entPos->mX = MathUtils::lerp(entPos->mX, primeTarget.mPos->mX, (myEng->mSpeed * 0.1f));
                entPos->mY = MathUtils::lerp(entPos->mY, primeTarget.mPos->mY, (myEng->mSpeed * 0.1f));

                break;

            case 1:

                primeTarget.mHel->mHitBy.push_back(std::pair<std::string, float>(entReg->mName, phasers->mDamage));

                break;

            case 2:

                primeTarget.mHel->mHitBy.push_back(std::pair<std::string, float>(entReg->mName, torpedos->mDamage));

                break;

            case 3:

                primeTarget.mHel->mHitBy.push_back(std::pair<std::string, float>(entReg->mName, phasers->mDamage));
                primeTarget.mHel->mHitBy.push_back(std::pair<std::string, float>(entReg->mName, torpedos->mDamage));

                break;

            default:
                break;
            }

        }


    private:

        Scene& mGameScene;
    };

}

#endif //ENTERPRISE_SYSTEM_H