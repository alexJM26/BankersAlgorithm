# Banker's Algorithm
A program that will examine the current state of a system, determine if it is in a safe state or not, and produce a safe sequence if it is safe. 

## General Information

This project was completed for cs33211 (Operating Systems) at Kent State University on 04/19/24.

## Additional Information

Further documentation information can be found in this project's wiki.

## Usage

Before running the program, store the current state of the system in the following format:

- Enter your information in the following order: Allocation Matrix, Maximum Matrix, Available Vector.
- End each row with a ';'.
- To signal you have finished typing one of the pieces of information, include a '-'.
- Seperate all tokens with a single whitespace ' '. 

An example of this is seen below.
| Process | Allocation | Max | Available |
| :--- | :---: | :---: | :---: |
|      | A  B  C | A  B  C | A  B  C |
| P0   | 0  1  0 | 7  5  3 | 3  2  2 |
| P1   | 2  0  0 | 3  2  2 | 
| P2   | 3  0  2 | 9  0  2 | 
| P3   | 2  1  1 | 2  2  2 | 
| P4   | 0  0  2 | 4  3  3 | 
```bash
0 1 0 ; 2 0 0 ; 3 0 2 ; 2 1 1 ; 0 0 2 ;
-
7 5 3 ; 3 2 2 ; 9 0 2 ; 2 2 2 ; 4 3 3 ;
-
3 3 2 ;
```

To compile the banker's algorithm program, enter the following command into the terminal.
```bash
g++ bankersAlgorithm.cpp dataStructures.cpp -o bankersAlgorithm
```

To run the program, enter the following command into the terminal.
```bash
./bankersAlgorithm
```

From here, answer the prompts. Ensure to include the file extension of any file names entered. 
