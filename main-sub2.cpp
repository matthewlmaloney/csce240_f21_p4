// Copyright 2021 Matthew Maloney
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::cout;
using std::string;

void readPuzzle(vector<vector<char>> &puzzle, string filename);
void readWords(vector<string> &words, string filename);
void printPuzzle(const vector<vector<char>> &puzzle);
void printWords(const vector<string> &words);
void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found);
bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end);

int main(int argc, char **argv) {
  string puzzleFileName;
  string wordsFileName;
  vector<vector<char>> puzzle;
  vector<string> words;
  if (argc != 3) {
    cout << "Usage: ./sub2 puzzle.txt words.txt\n";
    exit(0);
  }
  puzzleFileName = argv[1];
  wordsFileName = argv[2];
  readPuzzle(puzzle, puzzleFileName);
  readWords(words, wordsFileName);
  printPuzzle(puzzle);
  printWords(words);

  for (auto word : words) {
    vector<int> start;
    vector<int> end;
    bool found;
    found = findWord(puzzle, word, start, end);
    printLocation(word, start, end, found);
    end.clear();
    start.clear();
  }
  return 0;
}

void readPuzzle(vector<vector<char>> &puzzle, string filename) {
  vector<char> lineholder;
  string line;
  std::ifstream in(filename);
  if (in.is_open()) {
    while (getline(in,line))
    {
          for(char &c : line)
            {
              if (c != ' ')
                lineholder.push_back(c);
            }
          puzzle.push_back(lineholder);
          lineholder.clear();
          
          
    }
  }
  in.close();
    return;
}

void readWords(vector<string> &words, string filename) {
    string line;
  std::ifstream in;
  in.open(filename);
  while (in >> line)
  {
    words.push_back(line);
  }
  return;

}

void printPuzzle(const vector<vector<char>> &puzzle) {
    for(int i=0; i<puzzle.size(); i++)
      {
        for(int j=0; j<puzzle[i].size(); i++)
        {
          cout << puzzle[i][j] << " ";
        }
        cout << '\n';
      }
    return;
}

void printWords(const vector<string> &words) {
  for(auto word: words)
  {
    cout << word << '\n';
  }
    return;
}

void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found) {
    if(found)
     {
       cout << "word " << word <<" found at (" << start[0] << ", " << start[1] << ") -> (" << end[0] << ", " << end[1] << ")\n";
     }

    else
    {
      cout << "Word " << word << " not found" << '\n';
    }
    return;
}

bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
    return false;
  
}