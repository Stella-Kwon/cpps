#include "Warlock.hpp"

int main() {

//   Warlock bob;                           // Does not compile
  Warlock bob("Bob", "the magnificent"); // Compiles
  Warlock jim("Jim", "the nauseating");  // Compiles
//   bob = jim;                             // Does not compile
//   Warlock jack(jim);                     // Does not compile

  Warlock const richard("Richard", "Mistress of Magma"); //const object
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock *jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}