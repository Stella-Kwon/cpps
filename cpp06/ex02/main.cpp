#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base *generate(void) 
{
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(NULL));
    seeded = true;
  }
  // Generate a random number between 0 and 2
  int random = std::rand() % 3;

  switch (random) {
  case 0:
    std::cout << "Generated an A object" << std::endl;
    return new A();
  case 1:
    std::cout << "Generated a B object" << std::endl;
    return new B();
  case 2:
    std::cout << "Generated a C object" << std::endl;
    return new C();
  default:
    return NULL; // This should never happen
  }
}

void identify(Base *p) {
  // Using dynamic_cast with pointers, no exception even fails, returns nullptr.
  // so just need to check nullptr if it fails.
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
  // Using dynamic_cast with references
  // When dynamic_cast fails with references, it throws an exception. 
  // so have to catch with throw and try-catch

  try {
    A &refA = dynamic_cast<A &>(p);
    (void)refA; // To avoid unused variable warning
    std::cout << "A" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }

  try {
    B &refB = dynamic_cast<B &>(p);
    (void)refB;
    std::cout << "B" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }

  try {
    C &refC = dynamic_cast<C &>(p);
    (void)refC;
    std::cout << "C" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }

  std::cout << "Unknown type" << std::endl;
}

int main() {
  std::cout << "----- Testing generate function -----" << std::endl;
  Base *obj1 = generate();
  Base *obj2 = generate();
  Base *obj3 = generate();
  Base *obj4 = nullptr;
  // Test pointer identification
  std::cout << "\n----- Testing identify with pointers -----" << std::endl;
  std::cout << "obj1 is: ";
  identify(obj1);

  std::cout << "obj2 is: ";
  identify(obj2);

  std::cout << "obj3 is: ";
  identify(obj3);

  std::cout << "obj4 is: ";
  identify(obj4);

  // Test reference identification
  std::cout << "\n----- Testing identify with references -----" << std::endl;
  std::cout << "obj1 is: ";
  identify(*obj1);

  std::cout << "obj2 is: ";
  identify(*obj2);

  std::cout << "obj3 is: ";
  identify(*obj3);

  delete obj1;
  delete obj2;
  delete obj3;

  return 0;
}