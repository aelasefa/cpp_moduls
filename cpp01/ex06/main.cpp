#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac != 2)
	{
		std::cout << "HARL LOVES HIS PROGRAM TO BE USED LIKE :\n./harlFilter <level>" << std::endl;
        return 1;
	}
	std::string level = av[1];
    int lvl = -1;
    if (level == "DEBUG") lvl = 0;
    else if (level == "INFO") lvl = 1;
    else if (level == "WARNING") lvl = 2;
    else if (level == "ERROR") lvl = 3;

    switch (lvl)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" 
                      << std::endl;
    }
    return 0;
}
