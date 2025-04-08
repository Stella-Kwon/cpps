// #include "AForm.hpp"
// #include "Bureaucrat.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "Intern.hpp"


// int main() {
//   try {

//     Bureaucrat boss("Boss", 140);

//     Intern someRandomIntern;


//     // Create forms
//     AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
//     AForm *robot = someRandomIntern.makeForm("robotomy request", "Bender");
//     AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Douglas Adams");

//     // Test invalid form name
//     AForm *invalid = someRandomIntern.makeForm("invalid form type", "target");
//     if (invalid) {
//       delete invalid; // This shouldn't execute
//     }

//     std::cout << "\n--- Testing valid forms ---" << std::endl;
//     if (shrub) {
//       boss.signForm(*shrub);
//       boss.executeForm(*shrub);
//       delete shrub;
//     }

//     if (robot) {
//       boss.signForm(*robot);
//       boss.executeForm(*robot);
//       delete robot;
//     }

//     if (pardon) {
//       boss.signForm(*pardon);
//       boss.executeForm(*pardon);
//       delete pardon;
//     }
//   } catch (std::exception &e) {
//     std::cout << "Exception: " << e.what() << std::endl;
//   }
//   return 0;
// }


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void) {
	std::cout << "==== TEST 1 ====" << std::endl;
	try {
		Intern intern1;
		Bureaucrat director("Director", 45);
		AForm* rrf = intern1.makeForm("robotomy request", "President");
		director.signForm(*rrf);
		director.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "==== TEST 2 ====" << std::endl;
	try {
		Intern intern2;
		Bureaucrat president("President", 1);
		AForm* ppf = intern2.makeForm("presidential pardon", "Manager");
		president.signForm(*ppf);
		president.executeForm(*ppf);
		delete ppf;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 3 ====" << std::endl;
	try {
		Intern intern3;
		Bureaucrat worker("Worker", 145);
		AForm* scf = intern3.makeForm("shrubbery creation", "Team Lead");
		worker.signForm(*scf);
		worker.executeForm(*scf);
		delete scf;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 4 ====" << std::endl;
	try {
		Intern intern4;
		Bureaucrat teamLead("Team Lead", 70);
		AForm* rf = intern4.makeForm("random", "Employee");
    if (rf)
  {		teamLead.signForm(*rf);
		teamLead.executeForm(*rf);
		delete rf;}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}