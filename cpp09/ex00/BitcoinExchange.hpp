#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <cstdlib>
#include <cctype>

bool parseDataFile(const char* filename,
                   std::map<std::string, double>& rates);


void processInputFile(const char* filename,
                      const std::map<std::string, double>& rates);
#endif
