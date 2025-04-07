#pragma once

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const override;

private:
  std::string target;
};
