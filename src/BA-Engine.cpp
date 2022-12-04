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

	while (run)
	{
		//TODO: calculate Elapsed time
		float elapsedTime = 0.0f;
		kmc.update(elapsedTime);
		run = kmc.getIsRunning();
	}

	return 0;
}