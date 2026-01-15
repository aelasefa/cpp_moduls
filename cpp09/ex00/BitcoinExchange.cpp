#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>

std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && isspace(s[start]))
        start++;

    size_t end = s.size();
    while (end > start && isspace(s[end - 1]))
        end--;

    return s.substr(start, end - start);
}


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDateFormat(const std::string& date) {
    if (date.length() != 10)
        return false;

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return false;
        } else if (!isdigit(date[i])) {
            return false;
        }
    }
    return true;
}

bool isValidDateValue(const std::string& date) {
    int year  = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day   = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    if (date < "2009-01-02")
        return false;

    return true;
}

bool isValidDate(const std::string& date) {
    return isValidDateFormat(date) && isValidDateValue(date);
}


bool isValidNumber(const std::string& s) {
    int i = 0;
    bool dot = false;

    if (s.empty())
        return false;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; i < (int)s.length(); i++) {
        if (s[i] == '.') {
            if (dot)
                return false;
            dot = true;
        } else if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}


bool parseDataFile(const char* filename,
                   std::map<std::string, double>& rates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open data file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ',') ||
            !std::getline(ss, rateStr))
            continue;

        date = trim(date);
        rateStr = trim(rateStr);

        rates[date] = atof(rateStr.c_str());
    }

    file.close();
    return true;
}


bool getRateForDate(const std::map<std::string, double>& rates,
                    const std::string& date,
                    double& rate) {
    std::map<std::string, double>::const_iterator it = rates.lower_bound(date);

    if (it != rates.end() && it->first == date) {
        rate = it->second;
        return true;
    }

    if (it == rates.begin())
        return false;

    --it;
    rate = it->second;
    return true;
}


void processInputFile(const char* filename,
                      const std::map<std::string, double>& rates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        line = trim(line);

        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') ||
            !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!isValidNumber(valueStr)) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        double value = atof(valueStr.c_str());

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate;
        if (!getRateForDate(rates, date, rate)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
		std::cout << std::fixed << std::setprecision(2);
        std::cout << date << " => " << value << " = "
                  << value * rate << std::endl;
    }

    file.close();
}


