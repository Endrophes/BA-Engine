#include "PrecompiledHeader.h"
#include "Kobayashi-Maru.h"

#include "../Components/ShipRegistry.h"
#include "../Components/Position.h"

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

		// Create the attackers
		for (int i = 1; i <= kNumberOfAttackers; i++)
		{
			Entity attacker = mScene.createEntity();
			attacker.addComponent<Position>(5.0f, 10.0f);
			attacker.addComponent<ShipRegistry>(
				("RomulanShip-" + std::to_string(i)),
				"Romulan",
				i
			);

			//auto shipReg = attacker.getComponent<ShipRegistry>();

			//log_d("Test")
		}

		//Create the player

		mPlayer = mScene.createEntity();
		mPlayer.addComponent<Position>(5.0f, 10.0f);
		mPlayer.addComponent<ShipRegistry>(
			("Enterprise"),
			"Federation",
			1701
		);
	}

	void KobayashiMaruControler::start()
	{
		
	}

	void KobayashiMaruControler::update(const float pElapsedTime)
	{

	}

	void KobayashiMaruControler::shutdown()
	{

	}
}