#include "state.hpp"

// takes input file and turns it into a state structure
state tableInput(std::string fileName) {

    state current; // holds state stored in file
    std::ifstream file(fileName);

    // check if file has opened correctly
    if (!file.is_open()) {
        std::cout << "ERROR: Failed to open file.\n";
        exit(1); // exit the program
    }

    std::string token; // holds current token
    std::vector<int> currentRow; // hollds current row

    // get allocation matrix
    while (file >> token && token != "-") {
        if (token == ";") {
            current.allocation.push_back(currentRow); // add row to allocation matrix
            currentRow = {}; // make current row empty
        }
        else {
            currentRow.push_back(std::stoi(token)); // put number into current row
        }
    }

    // get max matrix
    while (file >> token && token != "-") {
        if (token == ";") {
            current.max.push_back(currentRow); // add row to max matrix
            currentRow = {}; // make current row empty
        }
        else {
            currentRow.push_back(std::stoi(token)); // put number into current row
        }
    }

    // get available vector
    while (file >> token && token != ";") {
        current.available.push_back(stoi(token)); // put number into vector
    }

    // make need matrix
    current.need = current.allocation; // match sizes
    for (int i = 0; i < current.allocation.size(); ++i) {
        for (int j = 0; j < current.allocation[i].size(); ++j) {
            current.need[i][j] = current.max[i][j] - current.allocation[i][j]; // calculate values 
        }
    }

    file.close(); // close input stream
    return current; // return the state of the system

}


// returns if the state is safe and prints a safe sequence if it is
bool safetyAlgorithm(state current) {

    // get size of vectors and matrices
    int n = current.max.size(), m = current.available.size();

    // array for holding the safe sequence
    int safeSequence[n];

    // initalize work and finish vectors
    std::vector<int> work = current.available; 
    std::vector<bool> finish(n); 
    for (int i = 0; i < n; ++i) {
        finish[i] = false;
    }

    bool found = true; // flags if a valid process is found
    int seqNum = 0; // tracks current index of safe sequence
    int i = 0; // tracks the process number 

    while (found != false) { // loop until no valid process is found

        found = false; // assume no process is found
        while (i < n && found == false) { // look through all processes

            if (finish[i] == false) {

                // check if Need[i] <= Work
                found = true;
                for (int j = 0; j < m; j++) {
                    if (current.need[i][j] > work[j])
                        found = false;
                }

            }

            if (found == false) i++; // if no process found, increment i
        }

        if (found == true) { // if valid process found, make computations

            // update work values
            for (int j = 0; j < m; ++j) {
                work[j] = work[j] + current.allocation[i][j];
            }

            // update finish value
            finish[i] = true;

            // put process into safe sequence
            safeSequence[seqNum] = i;
            seqNum++;

            // if on last process, reset to the first
            if (i == n-1) i = 0;
        }
    }

    // check if system is in a safe state
    for (int i = 0; i < n; ++i) {
        if (finish[i] == false) {
            std::cout << "The system IS NOT in a safe state!\n";
            return false;
        }
    }

    // output result and sequence if system is in a safe state
    std::cout << "The system IS in a safe state!\n" << "The safe sequence: ";
    for (int i = 0; i < n; ++i) {
        std::cout << 'P' << safeSequence[i] << " ";
    }
    std::cout << std::endl;
    return true;

}
