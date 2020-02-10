#include "Word.h"

void Word::getARandomWord() {
  string w; // random word

  // getting random word
  const int totalNumberOfWordsOnTextFile = 49;
  int randomIndex = rand() % totalNumberOfWordsOnTextFile + 0;
  w = words.at(randomIndex)
}

Word::Word() {
  srand ((unsigned)time(NULL));
  rand(); rand(); rand();
initializeWordsFromFileIntoVector();
}

void Word::initializeWordsFromFileIntoVector() {
  ifstream wordBank;
  string inputtedWord;
  vector<string> g2;

  wordBank.open("word.txt");

    while(true) {

      if (wordBank.eof()) {
        break;
      }
        wordBank >> inputtedWord;
        words.push_back(inputtedWord);
    }
  wordBank.close();
}
