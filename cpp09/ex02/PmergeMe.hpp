#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void parseInput(int argc, char **argv, std::vector<int> &numbers);
void sortVector(std::vector<int> &input);
void sortDeque(std::deque<int> &input);
#endif
