// #include "AForm.hpp"
// #include "Bureaucrat.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include <iostream>

// int main() {
//   try {
//     // Create bureaucrats with different grades
//     Bureaucrat a("a", 140);
//     Bureaucrat b("b", 70);
//     Bureaucrat c("c", 25);
//     Bureaucrat d("d", 1);

//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << c << std::endl;
//     std::cout << d << std::endl << std::endl;

//     // Create forms
//     ShrubberyCreationForm shrub("garden");
//     RobotomyRequestForm robot("Bender");
//     PresidentialPardonForm pardon("Douglas Adams");

//     std::cout << "--- Shrubbery Form Tests ---" << std::endl;
//     std::cout << shrub << std::endl;
//     // a can sign but not execute
//     a.signForm(shrub);
//     a.executeForm(shrub);
//     b.executeForm(shrub);

//     std::cout << "\n--- Robotomy Form Tests ---" << std::endl;
//     std::cout << robot << std::endl;
//     // b can sign
//     b.signForm(robot);
//     b.executeForm(robot);
//     c.executeForm(robot);

//     std::cout << "\n--- dial Pardon Form Tests ---" << std::endl;
//     std::cout << pardon << std::endl;
//     // c can sign
//     c.signForm(pardon);
//     c.executeForm(pardon);
//     d.executeForm(pardon);

//     std::cout << "\n--- Testing unsigned form execution ---" << std::endl;
//     // Create a new unsigned form
//     PresidentialPardonForm unsignedPardon("Arthur Dent");
//     d.executeForm(unsignedPardon); // Should fail because it's not signed
//   } 
//   catch (std::exception &e) {
//     std::cout << "Exception: " << e.what() << std::endl;
//   }

//   return 0;
// }

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int	main(void) {
	std::cout << "==== TEST 1 ====" << std::endl;
	try {
		ShrubberyCreationForm sForm1("Amy");
		Bureaucrat arborist1("Arborist1", 137);
		arborist1.signForm(sForm1);
		arborist1.executeForm(sForm1);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 2 ====" << std::endl;
	try {
		ShrubberyCreationForm sForm2("Bob");
		Bureaucrat arborist2("Arborist2", 140);
		arborist2.signForm(sForm2);
		arborist2.executeForm(sForm2);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 3 ====" << std::endl;
	try {
		RobotomyRequestForm rForm("Charlie");
		Bureaucrat robot("Robot", 40);
		robot.signForm(rForm);
		robot.executeForm(rForm);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 4 ====" << std::endl;
	try {
		PresidentialPardonForm pForm1("David");
		Bureaucrat president1("President1", 1);
		president1.signForm(pForm1);
		president1.executeForm(pForm1);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 5 ====" << std::endl;
	try {
		PresidentialPardonForm pForm2("Flora");
		Bureaucrat president2("President", 0);
		president2.signForm(pForm2);
		president2.executeForm(pForm2);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n###### Test RobotomyRequestForm Randomness ######" << std::endl;
    try
    {
        Bureaucrat highRank("HighRank", 1);
        RobotomyRequestForm robot2("target2");
        std::cout << highRank << std::endl << robot2 << std::endl;
        highRank.signForm(robot2);
        std::cout << robot2 << std::endl;

        for (int i = 0; i < 10; ++i)
        {
            highRank.executeForm(robot2);
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}