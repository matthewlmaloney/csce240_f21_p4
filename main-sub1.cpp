// Copyright 2021 <Your name here>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::string;

void readData(vector<string> &data, string filename);
void printData(const vector<string> &data);
vector<int> findMinHamming(const vector<string> & data, string test);
void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min);

int main(int argc, char **argv) {
  string filename;
  vector<string> data;
  if (argc != 2) {
    cout << "Usage: ./sub1 data.txt\n";
    exit(0);
  }
  filename = argv[1];
  readData(data, filename);
  for (auto line : data) {
    vector<int> ret;
    ret = findMinHamming(data, line);
    printMinDistance(data, line, ret);
  }
  return 0;
}

void readData(vector<string> &data, string filename) {
  return;
}

void printData(const vector<string> &data) {
  return;
}

vector<int> findMinHamming(const vector<string> & data, string test) {
  vector<int> ret; 
  
  return ret;
}

void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min) {
  return;
}
