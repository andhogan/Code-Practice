#include <iostream>
#include <cmath>

int main() {
  
  //Declaring and Initializing constants
  double a, b, c;
  std::cout << "Enter a: ";
  std::cin >> a;
  std::cout << "Enter b: ";
  std::cin >> b;
  std::cout << "Enter c: ";
  std::cin >> c;

  //Declaring and Initializing the roots
  double root1, root2;
  
  root1 = (-b + std::sqrt(b*b - 4*a*c)) / (2*a);
  root2 = (-b - std::sqrt(b*b - 4*a*c)) / (2*a);

  //Outputting the roots
  std::cout << "Your roots are as follows: \n";
  std::cout << "Root 1 = " << root1 << "\n";
  std::cout << "Root 2 = " << root2 << "\n";
  
}