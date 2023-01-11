/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#include "PrecompiledHeader.h"
#include "Kobayashi-Maru.h"

#include "../Components/ShipRegistry.h"
#include "../Components/Position.h"
#include "../Components/Component.h" // Has multiple components

#include "../Utilities/ConsoleUtils.h"

namespace BA_Engine
{
	KobayashiMaruControler::KobayashiMaruControler()
		: mScene(Scene())
		, mPlayer(mScene.createEntity())
	{
		
	}

	KobayashiMaruControler::~KobayashiMaruControler()
	{

	}

	void KobayashiMaruControler::setup()
	{

		setIsRunning(true);

		//TODO: REMOVE MAGIC NUMBERS!

		// Create the attackers
		for (int i = 1; i <= kNumberOfAttackers; i++)
		{
			Entity attacker = mScene.createEntity();
			attacker.addComponent<Position>(5.0f + (i), 10.0f + (i));
			attacker.addComponent<ShipRegistry>(
				("RomulanShip-" + std::to_string(i)),
				"Romulan",
				i
			);
			attacker.addComponent<Disruptor>(5.0f, 20.0f);
			attacker.addComponent<ImpulseEngines>(10.0f, 10.0f, true);
			attacker.addComponent<Health>(75.0f);
		}

		//Create the player

		mPlayer = mScene.createEntity();
		mPlayer.addComponent<Position>(0.0f, 0.0f);
		mPlayer.addComponent<ShipRegistry>(
			("Enterprise"),
			"Federation",
			1701
		);
		mPlayer.addComponent<Phaser>(10.0f, 10.0f, true);
		mPlayer.addComponent<PhotonTorpedo>(6.0f, 13.0f, true);
		mPlayer.addComponent<ImpulseEngines>(10.0f, 5.0f, true);
		mPlayer.addComponent<Health>(100.0f);

		mEntSys = new EnterpriseSystem(mScene);
		mRomSys = new RomulanSystem(mScene);

		mScene.addSystem(1, mEntSys);
		mScene.addSystem(2, mRomSys);
	}

	void KobayashiMaruControler::start()
	{
		printMessage("Welcome Cadet to the Beta Test of the Kobayashi-Maru V 0.1.0 (Text Edition)");
		printMessage("This text based form of the Kobayashi-Maru is intended to familiarize you to the concept of a No Win Scenario ");
		printMessage("In this exsersie, you will be given one of many variations of the test and then have to command your ship through it with a strict set of options");
		
		printMessage("");

		printMessage("This program has: The Battle of Narendra III");

		printMessage("");

		int option = ConsoleUtils::printAndGetOption(
			"Here are your options (type the number for the option):",
			std::vector<std::string>{
				"Learn more about The Battle of Narendra III",
				"Start Sim",
				"Exit"
			}
		);

		switch (option)
		{

		case 1:

			printMessage("Answering a distress call from the Klingon's. You in command of the Enterprise-C arrive to the Narendra III system.");

			printMessage("");

			printMessage("Simulation commencing");

			break;

		case 2:

			printMessage("Simulation commencing");

			printMessage("");

			break;

		case 3:

			setIsRunning(false);

			break;

		default:
			break;
		}
	}

	void KobayashiMaruControler::update(const float pElapsedTime)
	{
		mScene.onUpdate(1, pElapsedTime); // Run player logic
		mScene.onUpdate(2, pElapsedTime); // Run Romulan logic

		if (mPlayer.getComponent<Health>().mHealth <= 0)
		{
			//Game Over
			setIsRunning(false);
		}

		ConsoleUtils::clearConsole();
	}

	void KobayashiMaruControler::shutdown()
	{
		printMessage("");

		if (mPlayer.getComponent<Health>().mHealth <= 0)
		{
			printMessage("Simulation Terminated. The Enterprise was destroyed with all hands");
			printMessage("Take heart, their sacrifice help smooth over relations with the klingons.");
			printMessage("They have gone down in klingon history as honorable warriors they be honored to join in battle along side.");
			printMessage("Program Terminated");
		}
		else
		{
			printMessage("Program Terminated by user");
		}

		
		printMessage("");
	}
}