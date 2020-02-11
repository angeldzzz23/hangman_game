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

/*
void updateTableWithValidInput(char **chart, char player) {

  int row, col;
  string row_, col_;

  do {
    cout << "enter correct input: " << endl;
    cin >> row_ >> col_;

    // input validation
    if (itIsNumber(row_) && itIsNumber(col_)) {
      row = (int)stoi(row_);
      col = (int)stoi(col_);

    } else {
      continue;
    }

    if ((row >=0 && row <= 2) && (col >=0 && col <= 2)) {
      if (chart[row][col] == '*') {
        chart[row][col] = player;
        break;
      }

    }
} while(true);

}


*/
