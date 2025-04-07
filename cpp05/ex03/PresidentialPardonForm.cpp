#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), target("default") {
  std::cout << "Defaulted has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5), target(target) {
  std::cout << target << " has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy : " << target << " has been created" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
    std::cout << "Operator : " << target << " has been created" << std::endl;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << target << " has been destroyed\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  validationTarget(executor);
  std::cout << target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}