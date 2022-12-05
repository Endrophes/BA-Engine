/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of BA-Engine project.
 *
 * BA-Engine project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#include "PrecompiledHeader.h"
#include "Controllers/Kobayashi-Maru.h"

/// <summary>
/// The start of engine
/// </summary>
/// <returns>Error Codes</returns>
int main()
{
	bool run = true;
	BA_Engine::KobayashiMaruControler kmc;

	kmc.setup();

	kmc.start();

	while (run)
	{
		//TODO: calculate Elapsed time
		float elapsedTime = 0.0f;
		kmc.update(elapsedTime);
		run = kmc.getIsRunning();
	}

	kmc.shutdown();

	return 0;
}