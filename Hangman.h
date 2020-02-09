//
//
#ifndef HANGMAN
#define HANGMAN
#include <string>
#include <iostream>

using namespace std;

class Hangman
{
public:
  string userInput; // the letters or word the user has entered

  Hangman(string); // initializer. Just intiializes  randomWord with whatever was chosen.
  void printInstructions(); // show user how he will play
  void startGame(); // Starts a new game
  string guessedLetters; // this is where the correct letters will be stored
  void printGuessedLetters(); // prints guessed letter with a space 


private:
  string randomWord; // word that the user has to guess
  void clearScreen(); // clears the screen.
  bool userDidSkipInstruction(); // checks if the user skipped instructions
  void getCorrectUserInput();
  bool userInputIsAllLetters(string);
  bool isAWholeWord(); //
  void resetGuessedLetters();

};



#endif
