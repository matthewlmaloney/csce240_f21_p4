// Copyright 2021 Matthew Maloney
#include <iostream>
#include <fstream>
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
  printData(data);
  for (auto line : data) {
    vector<int> ret;
    ret = findMinHamming(data, line);
    printMinDistance(data, line, ret);
  }
  return 0;
}

void readData(vector<string> &data, string filename) {
  string line;
  std::ifstream in;
  in.open(filename);
  while (in >> line)
  {
    data.push_back(line);
  }
  return;
}

void printData(const vector<string> &data) {
  for(int i=0; i<data.size();i++)
  {
   cout << data[i] << '\n';
  }
  return;
}

vector<int> findMinHamming(const vector<string> & data, string test) {
   vector<int> ret;
  vector<int> holding;
  int size=0;
  int count=0;
  int itter=0;
  for(auto word: data)
  {
    count=0;
     if(test.length()!=word.length())
     {
       count=abs(test.length()-word.length());
       if(test.length()>word.length())
       {
         size=word.length()-1;
       }
       if(test.length()<word.length())
       {
        size=test.length()-1;
       }
     }

     for(int i=0;i<size;i++)
     {
       if(word[i]!=test[i])
          {
        count++;
          }
     }
     holding[itter]=count;
     itter++;
  }
   for(int i=0;i<holding.size();i++)
   { 
     if(holding[i]>holding[i+1])
     {
     ret.push_back(i+1);
     ret.push_back(holding[i]);
     }
   }

    return ret;
}

void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min) {
  cout << "The minimum hamming distance for "<< word <<" is "<< min[1] <<" (mathcing word: "<<data[min[0]]<<")";
  return;
}
