#include <iostream>
 
int main() {
 
  // The magic starts here
  int gryffindor = 0;
  int slytherin = 0;
  int hufflepuff = 0;
  int ravenclaw = 0;

  int ans1, ans2, ans3, ans4;
  std::cout << "The Sorting Hat Quiz!\n\n";
  

  //Q1
  std::cout << "Q1) When I'm dead, I want people to remember me as: \n\n";
  std::cout << "  1) The Good\n";
  std::cout << "  2) The Great\n";
  std::cout << "  3) The Wise\n";
  std::cout << "  4) The Bold\n\n";
  std::cin >> ans1;

  if (ans1 == 1) {
    hufflepuff++; 
    //gryffindor++ is the same as gryffindor = gryffindor +1, and same as gryffindor += 1
  }
  else if (ans1 == 2) {
    slytherin++;
  }
  else if (ans1 == 3) {
    ravenclaw++;
  }
  else if (ans1 == 4) {
    gryffindor++;
  }
  else {
    std::cout << "Invalid input.\n";
  }


  //Q2
  std::cout << "Q2) Dawn or Dusk?\n\n";
  std::cout << "  1) Dawn\n";
  std::cout << "  2) Dusk\n";
  std::cin >> ans2;

  if (ans2 == 1) {
    ravenclaw += 1;
    gryffindor += 1;
  }
  else if (ans2 == 2) {
    slytherin += 1;
    hufflepuff += 1;
  }
  else {
    std::cout << "Invalid input.\n";
}


  //Q3
  std::cout << "Q3) Which kind of instrument most pleases your ear?\n\n";
  std::cout << "  1) The violin\n";
  std::cout << "  2) The trumpet\n";
  std::cout << "  3) The piano\n";
  std::cout << "  4) The drum\n";
  std::cin >> ans3;

  if (ans3 == 1) {
    slytherin++; 
  }
  else if (ans3 == 2) {
    hufflepuff++;
  }
  else if (ans3 == 3) {
    ravenclaw++;
  }
  else if (ans3 == 4) {
    gryffindor++;
  }
  else {
    std::cout << "Invalid input.\n";
  }


  //Q4
  std::cout << "Q4) Which road tempts you most?\n\n";
  std::cout << "  1) The wide, sunny grassy lane\n";
  std::cout << "  2) The narrow, dark, lantern-lit alley\n";
  std::cout << "  3) The twisting, leaf-strewn path through woods\n";
  std::cout << "  4) The cobbled street lined (ancient buildings)\n";
  std::cin >> ans4;

  if (ans4 == 1) {
    hufflepuff++; 
  }
  else if (ans4 == 2) {
    slytherin++;
  }
  else if (ans4 == 3) {
    gryffindor++;
  }
  else if (ans4 == 4) {
    ravenclaw++;
  }
  else {
    std::cout << "Invalid input.\n";
  }


  //Steps 16 & 17
  int max = 0;
  std::string house;

  if (gryffindor > max) {
  max = gryffindor;
  house = "Gryffindor";
  }
  if (hufflepuff > max) {
    max = hufflepuff;
    house = "Hufflepuff";
  }
  if (ravenclaw > max) {
    max = ravenclaw;
    house = "Ravenclaw";
  }
  if (slytherin > max) {
    max = slytherin;
    house = "Slytherin";
  }
  
  std::cout << house << "!\n";
  std::cout << gryffindor << slytherin << hufflepuff << ravenclaw << "\n";


}
  