#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <sstream>
#include <stdexcept>

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other; // No data to copy in an Intern
  return *this;
}

Intern::~Intern() {}


AForm *Intern::makeForm(std::string const &formName, const std::string &target)
{
  // it will once generated but the alive only within in the function and until the program lives
  static const std::string formNames[NUM_FORMS] = {
      "shrubbery creation", "robotomy request", "presidential pardon"};

  // create array for function pointers
  FormCreator formCreators[NUM_FORMS] = {&Intern::createShrubberyForm,
                                         &Intern::createRobotomyForm,
                                         &Intern::createPresidentialForm};

    for (int i = 0; i < NUM_FORMS; i++) {
      if (formNames[i] == formName) {
        // need to *fromcreators to call the function as it is pointer itself
        AForm *form = (this->*formCreators[i])(target);
        std::cout << "Intern creates " << form->getName() << std::endl;
        return form;
      }
    }
    std::ostringstream out;
    out << "Error: form " << formName << "' does not exist";
    throw std::runtime_error(out.str());
    return nullptr;
}

AForm *Intern::createShrubberyForm(std::string const &target) const {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(std::string const &target) const {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(std::string const &target) const {
  return new PresidentialPardonForm(target);
}

