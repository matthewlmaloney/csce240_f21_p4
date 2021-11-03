# CSCE 240 Project 4 (60 pts) Due 11/16 at Midnight
For this assignment there will be 2 subtasks (30 points each). In each of the subtasks you will complete the task using a `std::vector`. 

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
2. `vector<int> findMinHamming(const vector<string> & data, string test)`
   - Returns the index of the element in `data` with the smallest hamming distance to the string `test` as well as the distance
      - Notice that the return is a vector of int. Each vector should have the index of the minimum string as the first element and the hamming distance as the second. 
   - For example, if data contains the following strings:
   ```
    cherry
    apple
    banana
   ```
   - Then findMinHamming(data, "apply!") would return a vector holding (1, 2) where 1 indicates the index of the match ("apple") and 2 indicates the hamming distance (2)
3. `void printMinDistance(const vector<string> &data, string word, const vector<int> min)`
   - Should print out in the form: "The minimum hamming distance for `word` is `min[1]` (matching word: `data[min[0]]`)"
   - Example data vector, word and output
   data
   ```
   cherry
   apple
   banana
   ```
   word
   ```
   cherries
   ```
   output
   ```
   The minimum hamming distance for cherries is 3 (matching word: cherry)
   ```

The `main()` function will call these functions in the following order: 
1. Call to your `readData` function ( I have already set up the command line arguments to read in the data file name )
2. Loop through your `data` vector
  - Each time through, a call to your `findMinHamming` and your `printMinHamming` function

### Compiling and Running Subtask 1
Compiling: 
```
g++ main-sub1.cpp -o sub1
```
Runnning:
```
./sub1 data.txt
```
## Subtask 2 - Word Search Solver
A popular diversion in the United States, "word find" (or "word search") puzzles ask the player to find each of a given set of words in a table filled with single letters. A word can read horizontally (left or right), vertically (up or down), or along a 45 degree diagonal (in any of the four directions) formed by consecutively adjacent cells of the table; it may wrap around the table’s boundaries, but it must read in the same direction with no zigzagging. The same cell of the table may be used in different words, but, in a given word, the same cell may be used no more than once. 

Your program will take in a puzzle and a list of words and return the start and end position of each word in the puzzle if found and an error message if not found.

You will complete the following functions in the `main-sub2.cpp` file: 
1. `void readPuzzle(vector<vector<char>> &puzzle, string filename)`: 
   - Reads data from `filename` (note that `filename` denotes the name of an actual file that you will send on the command line)
    - The data in this file is in the form: 
    ```
    A  D  D  T
    Q  I  L  L
    R  D  O  O
    ```
    - Each charcter in the file should be pushed to the vector `puzzle` passed into the function. 
2. `void readWords(vector<string> &words, string filename)`:
   - Reads data from `filename` (note that `filename` denotes the name of an actual file that you will send on the command line)
    - The data in this file is in the form: 
    ```
    OLD
    ADD
    DOG
    DID
    ARM
    ```
    - Each string in the file should be pushed to the vector `words` passed into the function. 
3. `void printLocation(string word, const vector<int> &start, const vector<int> &end, bool found)`
   - Should print out the starting and end location of the `word` only if `found` is true. 
      - The format for this should be "Word `word` found at (`start[0]`, `start[1]`) -> (`end[0]`, `end[1]`) where `word`, `start` and `end` come from the passed parameters (these will be filled in the function that follows!)
   - If `found` is false, it should print out: "Word `word` not found" (Examples below)
   - Example puzzle and word list followed by output
    ```
    A  D  D  T
    Q  I  L  L
    R  D  O  O
    ```
    word
     ```
    OLD
    ```
    output:
    ```
    Word OLD found at (3, 3) -> (0, 1)
    ```
4. `bool findWord(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end)`
   - Returns true if `word` is found and stores the start location (row, column of the first character) and the end location (row, column of the last character) in the `start` and `end` vectors. 
   - Returns false if `word` is not found 

The `main()` function will call these functions in the following order: 
1. Call to your `readPuzzle` function ( I have already set up the command line arguments to read in the puzzle file name )
2. Call to your `readWords` function ( I have already set up the command line arguments to read in the words file name )
3. Loop through your `words` vector
  - Each time through, a call to your `findWord` and your `printLocation` function

Example output: 
```
A  D  D  T
Q  I  L  L
R  D  O  O
```
word list
```
OLD
ADD
DOG
```
output:
```
Word OLD found at (3, 3) -> (0, 1)
Word ADD found at (0, 0) -> (0, 2)
Word DOG not found
```

### Compiling and Running Subtask 2
Compiling: 
```
g++ main-sub2.cpp -o sub2
```
Runnning:
```
./sub2 puzzle.txt words.txt
```
