#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  // Create a Data object
  Data originalData;
  originalData.name = "Test Data";
  originalData.value = 42;

  // Print the original data
  std::cout << "Original data address: " << &originalData << std::endl;
  std::cout << "Original data values: " << originalData.name << ", "
            << originalData.value << std::endl;

  // Serialize the data pointer
  uintptr_t serialized = Serializer::serialize(&originalData);
  std::cout << "Serialized value: " << serialized << std::endl;

  // Deserialize back to a pointer
  Data *deserialized = Serializer::deserialize(serialized);
  std::cout << "Deserialized pointer: " << deserialized << std::endl;

  // Print the deserialized data
  std::cout << "Deserialized data values: " << deserialized->name << ", "
            << deserialized->value << std::endl;

  // Verify the pointers are equal
  if (deserialized == &originalData) {
    std::cout << "SUCCESS: The deserialized pointer equals the original pointer"
              << std::endl;
  } else {
    std::cout
        << "ERROR: The deserialized pointer does not equal the original pointer"
        << std::endl;
  }

  return 0;
}