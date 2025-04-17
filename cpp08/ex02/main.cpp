#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T> void print(T &container) {
  for (auto it = container.begin(); it != container.end(); ++it) {
    std::cout << *it << " ";
  }
}

void basicTest() {
  std::cout << "\n===== basic Test =====\n";

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);

  std::cout << "Top: " << mstack.top() << std::endl;

  mstack.pop();
  std::cout << "Size after pop: " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  std::cout << "Stack contents: ";
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;

  //copy
  std::stack<int> s(mstack);
  std::cout << "Is the copied stack empty? " << (s.empty() ? "Yes" : "No")
            << std::endl;
  std::cout << "Copied stack size: " << s.size() << std::endl;
  std::cout << "Copied stack top: " << s.top() << std::endl;
}


void compareWithList() {
  std::cout << "\n===== Compare with list<> =====\n";

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(17);
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);

  std::cout << "MutantStack contents: ";
    print(mstack);
  std::cout << std::endl;

  std::cout << "List contents: ";
    print(lst);
  std::cout << std::endl;
}


void stringTest() {
  std::cout << "\n===== String test =====\n";

  MutantStack<std::string> strStack;
  strStack.push("Hello");
  strStack.push("World");
  strStack.push("MutantStack");
  strStack.push("Test");

  std::cout << "String stack top: " << strStack.top() << std::endl;
  strStack.pop(); // rm
  std::cout << "Top after pop: " << strStack.top() << std::endl;

  std::cout << "All strings: ";
    print(strStack);
  std::cout << std::endl;
}

void copyTest() {
  std::cout << "\n===== Copy Test =====\n";

  MutantStack<int> original;
  original.push(10);
  original.push(20);
  original.push(30);

  MutantStack<int> copied(original);
  std::cout << "Original top: " << original.top() << std::endl;
  std::cout << "Copied top: " << copied.top() << std::endl;

  original.pop();
  original.push(40);

  MutantStack<int> assigned;
  assigned = original;

  std::cout << "Original after changes: ";
    print(original);
  std::cout << std::endl;

  std::cout << "Copied (unchanged): ";
  print(copied);
  std::cout << std::endl;

  std::cout << "Assigned: ";
  print(assigned);
  std::cout << std::endl;
}


void iteratorModificationTest() {
  std::cout << "\n===== iterator modifying =====\n";

  MutantStack<int> mstack;
  for (int i = 0; i < 5; ++i) {
    mstack.push(i * 10);
  }

  std::cout << "Original values: ";
  print(mstack);
  std::cout << std::endl;

  //modified
  for (auto it = mstack.begin(); it != mstack.end(); ++it) {
    *it = *it + 5;
  }

  std::cout << "Modified values: ";
  print(mstack);
  std::cout << std::endl;
}



int main() {
  basicTest();
  compareWithList();
  stringTest();
  copyTest();
  iteratorModificationTest();

  std::cout << "\nAll Test has passed!" << std::endl;

  return 0;
}