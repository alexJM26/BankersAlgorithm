# Banker's Algorithm Model
A program that will examine the resource-allocation state of a system at a given snapshot in time, determine if it is a safe state or not, and produce a safe sequence (if the current state is safe). 

## General Information

This project was completed for cs33211 (Operating Systems) at Kent State University on 04/23/24.

The program takes a snapshot of the resource-allocation state of a system as input. This input must follow the format described under the "Usage" section. This input file is consumed and its information is used to create the data structures necessary for Banker's Algorithm. These data structures include the Maxmimum Matrix, the Allocation Matrix, the Need Matrix, and the Available Vector. The steps of the Safety Algorithm of Banker's Algorithm are then followed in order to inspect these data structures and check if the system is in a safe state.

The program provides output upon completion. This output indicates whether the input resource-allocation state is safe. Additionally, if it is safe, the output will provide one possible safe sequence. For any n processes described within the resource-allocation state, they will be output as so withiin the safe sequence: P0 P1 ... P(n-1) .

## Additional Information

Further documentation information can be found in this project's wiki.

## Usage

Before running the program, store the resource-allocation state of the system in a text file with the following format:

- Enter the information in the following order: Allocation Matrix, Maximum Matrix, Available Vector.
- End each row with a ';'.
- To signal the end of one of the pieces of information, include a '-'.
- Seperate all tokens with whitespace. 

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
g++ bankersAlgorithm.cpp state.cpp -o bankersAlgorithm
```

To run the program, enter the following command into the terminal.
```bash
./bankersAlgorithm
```

From here, answer the prompts. Ensure to include the file extension of any file names entered, along with their path relative to the program (if they are not in the same folder).<br> 
An example execution of the program may look like this.
```bash
[user@server Project2]$ ./bankersAlgorithm
Please enter the name of the file: stateTextFiles/assignmentExample.txt
--------
The system IS in a safe state!
The safe sequence: P1 P3 P4 P0 P2 
--------
Would you like to check another state? [y/n]: y
Please enter the name of the file: stateTextFiles/unsafeExample.txt
--------
The system IS NOT in a safe state!
--------
Would you like to check another state? [y/n]: n
Exiting the program...
```

## Environment Information
This project was run in Red Hat Enterprise Linux 8.<br>
The programs were compiled with g++ (GCC) version 8.5.0.
