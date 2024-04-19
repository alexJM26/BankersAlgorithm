#include "state.hpp"

int main() {

    std::string fileName; // holds file name from user

    bool exit = false; // tracks if user wants to exit
    char answer; // holds user input

    while (!exit) { // loop until user wants to exit

        std::cout << "Please enter the name of the file: ";
        std::cin >> fileName;

        // make file into a state structure
        state current = tableInput(fileName);

        // output if the state is safe (and a safe sequence if it is)
        std::cout << "--------" << std::endl;
        safetyAlgorithm(current); 
        std::cout << "--------" << std::endl;

        // see if user wants to check another file
        std::cout << "Would you like to check another state? [y/n]: ";
        std::cin >> answer;
        if (answer != 'y' && answer != 'Y') exit = true;

    }

    std::cout << "Exiting the program...\n";

}
