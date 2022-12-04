#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include "../PrecompiledHeader.h"

#define printMessage(pMsg)\
{\
       std::cout << pMsg << std::endl;\
};

namespace BA_Engine
{

	class ConsoleUtils
	{

	public:

		/// <summary>
		/// Prints a vector of options and returns what the user has selected.
		/// </summary>
		static int printAndGetOption(std::string mainMsg, std::vector<std::string> options)
		{
			printMessage(mainMsg);

			int opNum = 1;
			for (std::string option : options)
			{
				printMessage((std::to_string(opNum) + ". " + option).c_str());
				opNum++;
			}

			int optionPicked = 0;
			std::cin >> optionPicked;

			if (optionPicked == 0 || optionPicked > opNum)
			{
				printMessage("Invalid option");
				return printAndGetOption(mainMsg, options); //Recursion for the win?
			}

			return optionPicked;
		}

		/// <summary>
		/// Takes in an option vector, but returns a given int value paired with it
		/// Helpful for dynamic console values
		/// </summary>
		static int printAndGetOption(std::string mainMsg, std::vector<std::pair<std::string, int>> options)
		{
			printMessage(mainMsg);

			int opNum = 1;
			for (std::pair<std::string, int> option : options)
			{
				printMessage((std::to_string(opNum) + ". " + option.first).c_str());
				opNum++;
			}

			int optionPicked = 0;
			std::cin >> optionPicked;

			if (optionPicked == 0 || optionPicked > opNum)
			{
				printMessage("Invalid option");
				return printAndGetOption(mainMsg, options); //Recursion for the win?
			}

			return options[optionPicked].second;
		}
	};

}

#endif //CONSOLE_UTILS_H
