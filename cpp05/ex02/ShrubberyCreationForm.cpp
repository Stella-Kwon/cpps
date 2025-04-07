#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyForm", 145, 137), target("default") {
  std::cout << "Defaulted has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyForm", 145, 137), target(target) {
  std::cout << target << " has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy : " << target << " has been created" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
    std::cout << "Operator : " << target << " has been created" << std::endl;
}
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  
    validationTarget(executor);

    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());

  if (!file.is_open()) {
    std::cerr << "Error: could not create file " << filename << std::endl;
    return;
  }
  file << "    *    " << std::endl;
  file << "   ***   " << std::endl;
  file << "  *****  " << std::endl;
  file << " ******* " << std::endl;
  file << "*********" << std::endl;
  file << "    |    " << std::endl;
  file << std::endl;
  file << "    *    " << std::endl;
  file << "   ***   " << std::endl;
  file << "  *****  " << std::endl;
  file << " ******* " << std::endl;
  file << "*********" << std::endl;
  file << "    |    " << std::endl;

  file.close();
  std::cout << "Shrubbery created in file " << filename << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << target << " has been destroyed\n";
}
