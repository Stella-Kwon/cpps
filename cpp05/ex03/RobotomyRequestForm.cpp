#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <random>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), target("default") {
  std::cout << "Defaulted has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), target(target) {
  std::cout << target << " has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {
  std::cout << "Copy : " << target << " has been created" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
    std::cout << "Operator : " << target << " has been created" << std::endl;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << target << " has been destroyed\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  validationTarget(executor);

  std::cout << "Drilllling Noises" << std::endl;

  static std::mt19937 gen(std::time(nullptr));

  // uniformly generate the value over the given range
  static std::uniform_int_distribution<> dis(0, 1);
  if (dis(gen))
    std::cout << target << " has been robotomized successfully!" << std::endl;
  else
    std::cout << "Robotomy of " << target << " failed." << std::endl;
}
