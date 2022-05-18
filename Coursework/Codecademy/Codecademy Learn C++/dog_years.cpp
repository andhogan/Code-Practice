#include <iostream>

int main() {
  
  //string dog_name; 

  //std::cout << "What is your dog's name? \n";
  //std::cin >> dog_name;

  //My dog's age in regular years
  int dog_age;
  std::cout << "How old is your dog? \n";
  std::cin >> dog_age;

  //The first two years of a dog's life equate to 21 human years.
  int early_years = 21;

  //Each following year counts as 4 human years
  int later_years = (dog_age - 2) * 4;

  //To calculate a dog's years in human years:
  int human_years = early_years + later_years;
  
  std::cout << "Your dog is " << human_years << " years old in human years.\n";

}