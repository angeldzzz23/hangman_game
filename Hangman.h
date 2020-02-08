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
  string randomWord; // word that the user has to guess
  string userInput; // the letters or word the user has entered
  Hangman(string);
  void printInstructions(); // show user how he will play
private:
  void clearScreen();
  bool userDidSkipInstruction();






};



#endif
