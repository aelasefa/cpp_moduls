#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	    if (ac != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
	
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

	if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error: cannot open input file." << std::endl;
		return 1;
	}
	std::string content;
	std::string line;

	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += "\n";
	}
	infile.close();

	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;                               
		pos = found + s1.length();
	}

	result += content.substr(pos);
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error: cannot open output file." << std::endl;
		return 1;
	}
	outfile << result;
	outfile.close();
}
