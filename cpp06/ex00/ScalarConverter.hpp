#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
private:
  // Private constructor to prevent instantiation
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

  // Helper methods for detection and conversion
  static bool isChar(const std::string &literal);
  static bool isInt(const std::string &literal);
  static bool isFloat(const std::string &literal);
  static bool isDouble(const std::string &literal);

  static void convertFromChar(char value);
  static void convertFromInt(int value);
  static void convertFromFloat(float value);
  static void convertFromDouble(double value);

  // Special cases handling
  static bool isSpecialFloat(const std::string &literal);
  static bool isSpecialDouble(const std::string &literal);

public:
  static void convert(const std::string &literal);
};

#endif