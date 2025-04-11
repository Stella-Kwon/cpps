#include "Array.hpp"
#include <iostream>
#include <string>

#include "Array.hpp"
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void runTests(const std::string &typeName, const std::vector<T> &initialValues,
              const T &modifyValue) {
  std::cout << "\n===== Testing " << typeName << " Array =====" << std::endl;

  // Default constructor test
  Array<T> empty;
  std::cout << "Empty array size: " << empty.size() << std::endl;

  // Parameter constructor test
  unsigned int size = initialValues.size();
  Array<T> array(size);
  std::cout << typeName << " array size: " << array.size() << std::endl;

  // Default initialization test
  std::cout << "Default initialized values: ";
  for (unsigned int i = 0; i < array.size(); ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  // Initialize with values
  for (unsigned int i = 0; i < array.size(); ++i) {
    array[i] = initialValues[i];
  }

  std::cout << "Set values: ";
  for (unsigned int i = 0; i < array.size(); ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  // Copy constructor test
  Array<T> copy(array);
  std::cout << "Copy size: " << copy.size() << std::endl;
  std::cout << "Copy values: ";
  for (unsigned int i = 0; i < copy.size(); ++i) {
    std::cout << copy[i] << " ";
  }
  std::cout << std::endl;

  // Modify original, verify copy is unchanged
  if (array.size() > 1) {
    array[1] = modifyValue;
    std::cout << "After modifying original - Original[1]: " << array[1]
              << ", Copy[1]: " << copy[1] << std::endl;
  }

  // Assignment operator test
  Array<T> assigned;
  assigned = array;
  std::cout << "Assigned size: " << assigned.size() << std::endl;
  std::cout << "Assigned values: ";
  for (unsigned int i = 0; i < assigned.size(); ++i) {
    std::cout << assigned[i] << " ";
  }
  std::cout << std::endl;

  // Modify assigned, verify original is unchanged
  if (assigned.size() > 0) {
    assigned[0] = modifyValue;
    std::cout << "After modifying assigned - Original[0]: " << array[0]
              << ", Assigned[0]: " << assigned[0] << std::endl;
  }

  // Out of bounds test
  try {
    std::cout << "Attempting to access out of bounds index..." << std::endl;
    std::cout << array[size + 5] << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}

void testDefaultInitialization() {
  std::cout << "\n===== Testing Default Initialization =====" << std::endl;

  // Test default initialization as mentioned in the subject
  int *a = new int(); // creating only a pointer that holds one int value.
  std::cout << "Default initialized int value: " << *a << std::endl;
  delete a;

  // Test with our Array class
  Array<int> singleInt(1);
  std::cout << "Array's default initialized int: " << singleInt[0] << std::endl;

  Array<double> singleDouble(1);
  std::cout << "Array's default initialized double: " << singleDouble[0]
            << std::endl;

  Array<std::string> singleString(1);
  std::cout << "Array's default initialized string: " << "'" << singleString[0]
            << "'" << std::endl;
}

int main() {
  // Test int array
  std::vector<int> intValues = {0, 10, 20, 30, 40};
  runTests<int>("Integer", intValues, 999);

  // Test string array
  std::vector<std::string> stringValues = {"Hello", "World", "C++"};
  runTests<std::string>("String", stringValues, "Changed");

  // Test double array
  std::vector<double> doubleValues = {1.1, 2.2, 3.3, 4.4};
  runTests<double>("Double", doubleValues, 99.99);

  // Additional default initialization tests
  testDefaultInitialization();

  std::cout << "\nAll tests completed successfully!" << std::endl;
  return 0;
}