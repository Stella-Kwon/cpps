#include "span.hpp"
#include <iostream>
#include <random>

void testLargeSpan() {
    const int COUNT = 10000;
    Span largeSpan(COUNT);

    std::random_device rd; // will give you out different seed
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 1000000);

    std::vector<int> numbers; // empty vector in which the push_back will pushed from the end but it is now empty so from 0
    //ensure the space first in the vector
    numbers.reserve(COUNT);
    for (int i = 0; i < COUNT; i++) {
        numbers.push_back(distrib(gen));
    }

    largeSpan.addRange(numbers.begin(), numbers.end());

    std::cout << "Large span with " << COUNT << " random numbers:" << std::endl;
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
}

int main() {
  Span span(5); // Create a Span that can hold a maximum of 5 numbers

  try {
    span.addNumber(1);
    span.addNumber(3);
    span.addNumber(7);
    span.addNumber(9);
    span.addNumber(2);

    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;

    testLargeSpan();
    span.addNumber(6); // This will exceed the maximum size
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}