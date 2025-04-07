#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main() {
  try {

    Bureaucrat boss("Boss", 140);

    Intern someRandomIntern;


    // Create forms
    AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm *robot = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Douglas Adams");

    // Test invalid form name
    AForm *invalid = someRandomIntern.makeForm("invalid form type", "target");
    if (invalid) {
      delete invalid; // This shouldn't execute
    }

    std::cout << "\n--- Testing valid forms ---" << std::endl;
    if (shrub) {
      boss.signForm(*shrub);
      boss.executeForm(*shrub);
      delete shrub;
    }

    if (robot) {
      boss.signForm(*robot);
      boss.executeForm(*robot);
      delete robot;
    }

    if (pardon) {
      boss.signForm(*pardon);
      boss.executeForm(*pardon);
      delete pardon;
    }
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  return 0;
}