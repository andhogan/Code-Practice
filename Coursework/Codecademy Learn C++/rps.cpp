/*
Rock Paper Scissors Lizard Spock
(The Big Bang Theory)
*/


#include <iostream>
#include <stdlib.h>
 
int main() {
 
  // Live long and prosper
  srand (time(NULL));
  int computer = rand() % 3 + 1;
  int user = 0;


  //The Game
  std::cout << "====================\n";
  std::cout << "rock paper scissors!\n";
  std::cout << "====================\n";
  
  std::cout << "1) ✊\n";
  std::cout << "2) ✋\n";
  std::cout << "3) ✌️\n";
  std::cout << "shoot! \n\n";
  std::cin >> user;

  //The Outcome
  if (user == computer) {
    std::cout << "It's a tie!\n";
  }
  else if (user == 1 && computer == 3) {
    std::cout << "Rock crushes Scissors! You win!\n";
  }
  else if (user == 2 && computer == 1) {
    std::cout << "Paper covers Rock! You win!\n";
  }
  else if (user == 3 && computer == 2) {
    std::cout << "Scissors cuts Paper! You win!\n";
  }
  else {
    std::cout << "Sorry, computer beats you!\n";
  }
}