#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <cstdlib> 

std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && isspace(s[start]))
        ++start;
    size_t end = s.size();
    while (end > start && isspace(s[end - 1]))
        --end;
    return s.substr(start, end - start);
}

bool parseDataFile(const char* filename, std::map<std::string, double>& rates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open data file '" << filename << "'." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, '|')) {
            std::cerr << "Error: Invalid line (missing date): " << line << std::endl;
            continue;
        }
        date = trim(date);

        if (!std::getline(ss, rateStr)) {
            std::cerr << "Error: Invalid line (missing rate): " << line << std::endl;
            continue;
        }
        rateStr = trim(rateStr);

        double rate = atof(rateStr.c_str());
        if (rate == 0 && rateStr != "0" && rateStr != "0.0") {
            std::cerr << "Error: Invalid rate value on line: " << line << std::endl;
            continue;
        }

        rates[date] = rate;
    }
    file.close();
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " data_file" << std::endl;
        return 1;
    }

    std::map<std::string, double> bitcoinRates;

    if (!parseDataFile(argv[1], bitcoinRates)) {
        return 1;
    }

    return 0;
}

