#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Word {

public:
  Word();
  string word;
  void getARandomWord();
private:
  vector<string> words;
  void initializeWordsFromFileIntoVector();
};

#endif
