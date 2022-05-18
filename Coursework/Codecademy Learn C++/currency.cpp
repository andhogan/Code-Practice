#include <iostream>

int main() {
    
//Initializing and Declaring currencies
  double pesos, reais, soles;
  double dollars;

  std::cout << "Enter number of Colombian Pesos: ";
  std::cin >> pesos;
  std::cout << "Enter number of Brazilian Reais: ";
  std::cin >> reais;
  std::cout << "Enter number of Peruvian Soles: ";
  std::cin >> soles;
// Pesos conversion rate (to dollars): 0.00032
// Reais conversion rate: 0.27
// Soles conversion rate: 0.3
  double pesos_to_dollars = 0.00032;
  double reais_to_dollars = 0.27;
  double soles_to_dollars = 0.3;
  dollars = (pesos * pesos_to_dollars) + (reais * reais_to_dollars) + (soles * soles_to_dollars);

  //Display the amount of dollars you now have
  std::cout << "US Dollars = $" << dollars << "\n";

}