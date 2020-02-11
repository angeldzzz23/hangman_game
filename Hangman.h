//
//
#ifndef HANGMAN
#define HANGMAN
#include <string>
#include <iostream>
#include "Word.h"

using namespace std;

class Hangman
{
public:
  string userInput; // the letters or word the user has entered
  int score;

  Hangman(string); // initializer. Just intiializes  randomWord with whatever was chosen.
  Hangman();
  void printInstructions(); // show user how he will play
  void startGame(); // Starts a new game
  string guessedLetters; // this is where the correct letters will be stored
  void printGuessedLetters(); // prints guessed letter with a space
  Word word;

private:
  string randomWord; // word that the user has to guess

  bool wordhasNotBeenFound;
  void clearScreen(); // clears the screen.
  bool userDidSkipInstruction(); // checks if the user skipped instructions
  void getCorrectUserInput();
  bool userInputIsAllLetters(string);
  bool isAWholeWord();
  void resetGuessedLetters();
  void DoAction();
  void changeScoreBasedOnTheSimilarityOfUserInputAndRandomWord();
  bool letterUserInputLetterExistsInRandomWord();
  bool gameIsNotOver();
  void updateLetterInUserInputOnGuessedLetters();
  void displayOutputForWhenGameisOver();
  string getCorrectUserInput1();

};

#endif
