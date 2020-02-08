// TODO:
// This class should throw an error if the randomWord contains spaces


#include "Hangman.h"
#include <iomanip>
#include <ctype.h>
using namespace std;

Hangman::Hangman(string randomWord) {
  this->randomWord = randomWord;
}

// Finish later
void Hangman::printInstructions() {
  clearScreen();

        cout << setw(45) << "WELCOME TO HANGMAN" << endl;
        cout << endl;
        cout << "Press [enter] to read instructions or press any other key to skip" << endl;

        if (userDidSkipInstruction()) {
            clearScreen();
          cout << setw(30) <<"How to Play" << endl;
          cout << endl;
          cout << "* In each game You will be prompted with: _ _ _ _ _" << endl;
          cout << "* each underscore symbolizes a letter. "<< endl;
          cout << "* You can either enter a letter or the whole word." << endl;
          cout <<endl;
          cout << "Press [enter] to reads more or any other key to skip" << endl;

          if (userDidSkipInstruction()) {
            clearScreen();
            cout << setw(30)<<"SCORING"<< endl;
            cout << endl;
            cout << "* If you enter the letter wrong you will be penalize you will lose a try" << endl;
            cout << "* If you attempt to figure out the whole word " << endl;
            cout << "* You will win if correct. And lose if incorrect" << endl;
            cout << "* game only accepts lowercase input" << endl;
            cout << "* At end of the game, you are taken back into the game center" << endl;
            cout << "* You have a total of three tries" << endl;
            cout <<endl;
            cout << "[Press any key to start a new game]"<< endl;

            if (userDidSkipInstruction()) {
                clearScreen();
              return;
            } else {
                clearScreen();
              return;
            }

          } else {
            clearScreen();
            return;
          }

        } else {
          clearScreen();
          return;
        }
}

void Hangman::clearScreen() {
  cout << string(100, '\n') << endl;
}

bool Hangman::userDidSkipInstruction() {
  string str;
  getline(cin, str);

  if (str.length() == 0) {
      cout << endl << endl << endl;
      return true;
  }
 return false;

}

void Hangman:: startGame() {

  // this will include a do a while loop
  printInstructions();
  clearScreen();
  // Set guessedLetters to display _ _ _ _ _

  // getCorrectUserInput();

  // end game settings
  // do while - loop to check if the user will play again

  cout << "Would you like to play again or quit?" << endl;
  cout << "enter q to quit" << endl
  cout << "Enter p to play again" << endl;


}


// code made by Wardah
void Hangman::getCorrectUserInput() {

  string input;
  int counter = 0;
  do {
    cout << "Enter a letter or a word" << endl;
    getline(cin, input);

    // check if it is empty
    if (input.length() == 0) { continue; }

    // makes sure that all input is filled with alphabets
    if (!userInputIsAllLetters(input)) {continue;}



    // if it makes it down here it means that the userInput is correct
    counter = 1;
  }while (counter != 1);

  // initialize userInput with input
  userInput = input;

}

// Checking that the user Entered an array of letters
// not numbers should be accepted
bool Hangman::userInputIsAllLetters(string _userInput) {
  for (int i = 0; i < _userInput.length(); i++) {
    if (!isalpha(_userInput[i])) {
      return false;
    }
  }
  return true;
}
