#include "Word.h"

// initializes word
void Word::getARandomWord() {
  string w; // random word

  // getting random word
  const int totalNumberOfWordsOnTextFile = 49;
  int randomIndex = rand() % totalNumberOfWordsOnTextFile + 0;
  word = words.at(randomIndex);
}

Word::Word() {
  srand ((unsigned)time(NULL));
  rand(); rand(); rand();
  initializeWordsFromFileIntoVector();
  getARandomWord();
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
