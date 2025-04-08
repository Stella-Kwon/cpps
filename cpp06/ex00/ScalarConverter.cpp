#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

// Private constructor implementations
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}
ScalarConverter::~ScalarConverter() {}

// Detection methods
bool ScalarConverter::isChar(const std::string &literal) {
  return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string &literal) {
  if (literal.empty())
    return false;

  size_t startPos = 0;
  if (literal[0] == '+' || literal[0] == '-')
    startPos = 1;

  for (size_t i = startPos; i < literal.length(); i++) {
    if (!isdigit(literal[i]))
      return false;
  }
  return !literal.empty() && startPos < literal.length();
}

bool ScalarConverter::isFloat(const std::string &literal) {
  if (isSpecialFloat(literal))
    return true;

  if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
    return false;

  bool hasDecimalPoint = false;
  size_t startPos = 0;

  if (literal[0] == '+' || literal[0] == '-')
    startPos = 1;

  for (size_t i = startPos; i < literal.length() - 1; i++) {
    if (literal[i] == '.') {
      if (hasDecimalPoint)
        return false;
      hasDecimalPoint = true;
    } else if (!isdigit(literal[i])) {
      return false;
    }
  }

  return hasDecimalPoint;
}

bool ScalarConverter::isDouble(const std::string &literal) {
  if (isSpecialDouble(literal))
    return true;

  bool hasDecimalPoint = false;
  size_t startPos = 0;

  if (literal[0] == '+' || literal[0] == '-')
    startPos = 1;

  for (size_t i = startPos; i < literal.length(); i++) {
    if (literal[i] == '.') {
      if (hasDecimalPoint)
        return false;
      hasDecimalPoint = true;
    } else if (!isdigit(literal[i])) {
      return false;
    }
  }

  return hasDecimalPoint;
}

bool ScalarConverter::isSpecialFloat(const std::string &literal) {
  return literal == "nanf" || literal == "+inff" || literal == "-inff";
}

bool ScalarConverter::isSpecialDouble(const std::string &literal) {
  return literal == "nan" || literal == "+inf" || literal == "-inf";
}

// Conversion methods
void ScalarConverter::convertFromChar(char value) {
  // To char
  if (isprint(value))
    std::cout << "char: '" << value << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;

  // To int
  std::cout << "int: " << static_cast<int>(value) << std::endl;

  // To float
  std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;

  // To double
  std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int value) {
  // To char
  if (value >= 0 && value <= 127) {
    if (isprint(value))
      std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }

  // To int
  std::cout << "int: " << value << std::endl;

  // To float
  std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;

  // To double
  std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float value) {
  // To char
  if (isnan(value) || isinf(value)) {
    std::cout << "char: impossible" << std::endl;
  } else if (value >= 0 && value <= 127) {
    if (isprint(static_cast<int>(value)))
      std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }

  // To int
  if (isnan(value) || isinf(value) || value > std::numeric_limits<int>::max() ||
      value < std::numeric_limits<int>::min()) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  }

  // To float
  // Check if the value is a whole number
  if (value == static_cast<int>(value))
    std::cout << "float: " << value << ".0f" << std::endl;
  else
    std::cout << "float: " << value << "f" << std::endl;

  // To double
  if (value == static_cast<int>(value))
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
  else
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(double value) {
  // To char
  if (isnan(value) || isinf(value)) {
    std::cout << "char: impossible" << std::endl;
  } else if (value >= 0 && value <= 127) {
    if (isprint(static_cast<int>(value)))
      std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }

  // To int
  if (isnan(value) || isinf(value) || value > std::numeric_limits<int>::max() ||
      value < std::numeric_limits<int>::min()) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  }

  // To float
  if (isnan(value)) {
    std::cout << "float: nanf" << std::endl;
  } else if (isinf(value)) {
    if (value > 0)
      std::cout << "float: +inff" << std::endl;
    else
      std::cout << "float: -inff" << std::endl;
  } else if (value == static_cast<int>(value)) {
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
  } else {
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
  }

  // To double
  if (value == static_cast<int>(value))
    std::cout << "double: " << value << ".0" << std::endl;
  else
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
  if (isChar(literal)) {
    char c = literal[1];
    convertFromChar(c);
  } else if (isInt(literal)) {
    long value = atol(literal.c_str());
    if (value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min()) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: impossible" << std::endl;
      std::cout << "double: impossible" << std::endl;
      return;
    }
    convertFromInt(static_cast<int>(value));
  } else if (isFloat(literal)) {
    if (isSpecialFloat(literal)) {
      if (literal == "nanf")
        convertFromFloat(std::numeric_limits<float>::quiet_NaN());
      else if (literal == "+inff")
        convertFromFloat(std::numeric_limits<float>::infinity());
      else if (literal == "-inff")
        convertFromFloat(-std::numeric_limits<float>::infinity());
    } else {
      convertFromFloat(static_cast<float>(atof(literal.c_str())));
    }
  } else if (isDouble(literal)) {
    if (isSpecialDouble(literal)) {
      if (literal == "nan")
        convertFromDouble(std::numeric_limits<double>::quiet_NaN());
      else if (literal == "+inf")
        convertFromDouble(std::numeric_limits<double>::infinity());
      else if (literal == "-inf")
        convertFromDouble(-std::numeric_limits<double>::infinity());
    } else {
      convertFromDouble(atof(literal.c_str()));
    }
  } else {
    std::cout << "Invalid literal format" << std::endl;
  }
}