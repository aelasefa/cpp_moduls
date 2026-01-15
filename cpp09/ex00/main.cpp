#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, double> rates;

    if (!parseDataFile("data.csv", rates))
        return 1;

    processInputFile(argv[1], rates);
    return 0;
}
