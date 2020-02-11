#include <fstream>
#include <iostream>
#include <string>
#include "Hangman.h"
#include <vector>
#include <stdlib.h>
#include "Word.h"
#include <ctype.h>

const int SIZE = 40;
const int WORDS_SIZE = 49;

int getInput();
bool itIsNumber(string number);

int main(void) {

  int input;
  Hangman game;

  do {
    game.startGame();
    input = getInput();
    if (input == 3) {
      break;
    } else if (input == 1) {
      continue;
    }
  } while (true);


  return 0;
}

int getInput() {
  int choice;
  string digit;
do {
  cout << "enter 3 to quit" << endl;
  cout << "Enter 1 to continue" << endl;
  cin >> digit;

  if (itIsNumber(digit)) {
    choice = (int)stoi(digit);
    return choice;
  }

} while (true);


  return 3;
}

bool itIsNumber(string number) {

  for (int i = 0; i < number.length(); i++) {
    if (!isdigit(number[i])) {
      return false;
    }

  }
  return true;
}
