#include "Hangman.h"
#include <iomanip>
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
