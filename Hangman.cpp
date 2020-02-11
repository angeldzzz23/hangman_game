#include "Hangman.h"
#include <iomanip>
#include <ctype.h>
using namespace std;

// initializer with random word
Hangman::Hangman(string randomWord) {
  this->randomWord = randomWord;
  this->score = 0;
  this->wordhasNotBeenFound = true;
}

Hangman::Hangman() {
  word.getARandomWord();
  this->randomWord = this->word.word;
  cout << randomWord << endl;
  this->score = 0;
  this->wordhasNotBeenFound = true;
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

// clears the screen
void Hangman::clearScreen() {
  cout << string(100, '\n') << endl;
}

// checks if the user has skipped an instruction
bool Hangman::userDidSkipInstruction() {
  string str;
  getline(cin, str);

  if (str.length() == 0) {
      cout << endl << endl << endl;
      return true;
  }
 return false;

}

// Starts a new hangman game
void Hangman:: startGame() {

  static int timesPlayed = 0;

  clearScreen();
  word.getARandomWord();
  randomWord = word.word;
  cout << randomWord << endl;
  resetGuessedLetters();

    // do while - loop
    // keeps on asking the user for input till the user
    // has either won or lost
  do {
    clearScreen();
    printGuessedLetters();
    cout << "Total tries left: " << 3 - score << endl;
    cout << endl;

    // Get correct input from user
    getCorrectUserInput();
    DoAction();
    clearScreen();
  } while(gameIsNotOver());
  // display if user won or lost
  displayOutputForWhenGameisOver();

  // increment times timesPlayed
  timesPlayed++;
}

// code made by Wardah
// correct input makes sure the user
// only enters alphabetical letter
void Hangman::getCorrectUserInput() {

  string input;
  int counter = 0;
  do {
    cout << "Enter a letter or a word" << endl;
    cin >> input;

    // getline(cin, input);

    // check if it is empty
    if (input.length() == 0) { continue; }

    // makes sure that all input is filled with alphabets
    if (!userInputIsAllLetters(input)) {continue;}

    // if it makes it down here it means that the userInput is correct
    counter = 1;

  }while (counter == 0);

  // initialize userInput with input
  userInput = input;

}

  string Hangman::getCorrectUserInput1() {
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

    }while (counter == 0);

    // initialize userInput with input

    return input;


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

//If it is on letter or a whole word
bool Hangman::isAWholeWord() {
  return (userInput.length() > 1) ? true : false;
}


void Hangman::resetGuessedLetters() {
  guessedLetters.clear();
  userInput.clear();

  score = 0;
  for (int i = 0; i < randomWord.length(); i++) {
    guessedLetters.append("_");
  }

}

void Hangman::printGuessedLetters() {
  for (int i = 0; i < guessedLetters.length();i++) {
    cout << guessedLetters[i] << " ";
  }
  cout << endl;
}

void Hangman::DoAction() {
if (isAWholeWord()) // UserInput is a whole word
{
    // Check if UserInput is the randomWordWord
    // if they are equal you have won
    changeScoreBasedOnTheSimilarityOfUserInputAndRandomWord();

} else { // the user inputted one letter
  cout << "the user entered a letter" << endl;
    // check if the letter is in the randomWord
    // if it is replace the word
  if (letterUserInputLetterExistsInRandomWord()) {
    // update guessed letter
    updateLetterInUserInputOnGuessedLetters();
    // checkTheLengh of the word

  } else {
    // if it is not, then update score
    score += 1;
  }
}

}

void Hangman::changeScoreBasedOnTheSimilarityOfUserInputAndRandomWord() {
  if (userInput.length() != randomWord.length()) { score += 3; return;}

  // checks if userInput and random word are the same
  if (randomWord != userInput) {
    score += 3;
    return;
  }

  // if you make it down here, it means that both words are correct
  wordhasNotBeenFound = false;

}

bool Hangman::gameIsNotOver() {

  if (score == 3) {
    return false;
  }

  if (wordhasNotBeenFound == false) {
    return false;
  }

  // if the guessedLetters and randomWord are the same
  if (guessedLetters == randomWord) {
    return false;
  }


  return true;
}

bool Hangman::letterUserInputLetterExistsInRandomWord() {

  for (int i = 0; i < randomWord.length(); i ++) {
      if (userInput[0] == randomWord[i]) {
        return true;
      }
  }
  return false;
}

void Hangman::updateLetterInUserInputOnGuessedLetters() {

  for (int i = 0; i < randomWord.length(); i ++) {
      if (userInput[0] == randomWord[i]) {
        guessedLetters[i] = userInput[0];
      }
  }

}


void Hangman::displayOutputForWhenGameisOver() {
  clearScreen();
  if (score == 3) {
    // write this better
    cout << "You ran out of tries." << endl;
    cout << "the correct word is: " << randomWord << endl;
  }

  if (guessedLetters == randomWord) {
      cout << "You found the correct word: " << randomWord << endl;
  }

}
