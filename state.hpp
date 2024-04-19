#ifndef DATA_STRUCTURES_HPP_
#define DATA_STRUCTURES_HPP_

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

// data structures necessary for banker's algorithm
struct state {
    std::vector<int> available;
    std::vector<std::vector<int>> max;
    std::vector<std::vector<int>> allocation;
    std::vector<std::vector<int>> need;
};

// takes input file and turns it into a state structure
state tableInput(std::string fileName); 

// returns if the state is safe and prints a safe sequence if it is
bool safetyAlgorithm(state current); 

#endif
