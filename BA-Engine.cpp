
#include <iostream>

/// <summary>
/// The start of engine
/// </summary>
/// <returns>Error Codes</returns>
int main()
{
	bool run = true;

	std::cout << "Type \"exit\" to end the program" << std::endl;

	while (run)
	{
		std::string userinput;
		std::cin >> userinput;

		if (userinput == "Exit" || userinput == "exit")
		{
			std::cout << "Program terminated by user." << std::endl;
			run = false;
		}
		else
		{
			std::cout << "unknown command" << std::endl;
		}
	}

	return 0;
}