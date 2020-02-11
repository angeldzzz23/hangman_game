#include <fstream>
#include <iostream>
#include <string>
#include "Hangman.h"
#include <vector>
#include <stdlib.h>
#include "Word.h"

const int SIZE = 40;
const int WORDS_SIZE = 49;

void randomFunction();

int number;

int main(void) {
    Hangman game;
    int input;
  do {
    game.startGame();
    cout << "enter 3 to quit" << endl;
    cout << "Enter 1 to continue" << endl; 
    cin >> input;

    if (input == 3) {
      break;
    } else if (input == 1) {
      continue;
    }

  } while (true);

  return 0;
}
