# CSCE 240 Project 4 (60 pts) Due 11/16 at Midnight
For this assignment there will be 3 subtasks. You will choose 2 out of 3 to complete for credit and the third (if you choose to complete it will be extra credit). Each task is worth 30 points if it is contributing to the overall 60 (ie. one of the 2 that you chose) or 15 if it is the one you are attempting for extra credit. In each of the subtasks you will complete the task using a `std::vector`. 

## Subtask 1 - Hamming Distance
The Hamming distance between two strings of equal length can be defined as the number of positions at which the corresponding symbols are different. 

For example:

hamming_distance("thisisate**st**", "thisisate**mp**") `== 2` 

hamming_distance("**T**his is a test", "**t**his is a test") `== 1` 

hamming_distance("this is a ", "this is a **test**") `== 4`

You will complete the following functions in the `main-sub1.cpp`: 
1. `void readData(vector<string> &data, string filename)`: 
   - Reads data from `filename` (note that `filename` denotes the name of an actual file that you will send on the command line)
    - The data in this file is in the form: 
    ```
    string 1
    string 2
    string 3
    ...
    ```
    - Each line in the file should be pushed to the vector `data` passed into the function. 
2. `int findMinHamming(const vector<string> & data, string test)`
   - Returns the index of the element in `data` with the smallest hamming distance to the string `test`
   - For example, if data contains the following strings:
   ```
    cherry
    apple
    banana
   ```
   - Then findMinHamming(data, "apply") would return index 1 (the index of apple).
3. `vector<vector<int>> calculateHammingAll(vector<string>)`
## Subtask 2 - Word Search Solver
A popular diversion in the United States, "word find" (or "word search") puzzles ask the player to find each of a given set of words in a square table filled with single letters. A word can read horizontally (left or right), vertically (up or down), or along a 45 degree diagonal (in any of the four directions) formed by consecutively adjacent cells of the table; it may wrap around the table’s boundaries, but it must read in the same direction with no zigzagging. The same cell of the table may be used in different words, but, in a given word, the same cell may be used no more than once. 

Write a program for solving this puzzle. Your program will take in a puzzle and then a word and return the start and end position of the word in the puzzle if found and an error message if not found.

## Subtask 3 - Grade Calculator
This subtask will operate on two different vectors. One vector (std::vector<string) will hold the names of the students and one vector (std::vector<double>) that will hold the grades for each student.
