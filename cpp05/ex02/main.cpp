#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  try {
    // Create bureaucrats with different grades
    Bureaucrat a("a", 140);
    Bureaucrat b("b", 70);
    Bureaucrat c("c", 25);
    Bureaucrat d("d", 1);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl << std::endl;

    // Create forms
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Douglas Adams");

    std::cout << "--- Shrubbery Form Tests ---" << std::endl;
    std::cout << shrub << std::endl;
    // a can sign but not execute
    a.signForm(shrub);
    a.executeForm(shrub);
    b.executeForm(shrub);

    std::cout << "\n--- Robotomy Form Tests ---" << std::endl;
    std::cout << robot << std::endl;
    // b can sign
    b.signForm(robot);
    b.executeForm(robot);
    c.executeForm(robot);

    std::cout << "\n--- dial Pardon Form Tests ---" << std::endl;
    std::cout << pardon << std::endl;
    // c can sign
    c.signForm(pardon);
    c.executeForm(pardon);
    d.executeForm(pardon);

    std::cout << "\n--- Testing unsigned form execution ---" << std::endl;
    // Create a new unsigned form
    PresidentialPardonForm unsignedPardon("Arthur Dent");
    d.executeForm(unsignedPardon); // Should fail because it's not signed
  } 
  catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return 0;
}