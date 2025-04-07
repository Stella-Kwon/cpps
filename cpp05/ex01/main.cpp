#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat andrew("Andrew", 80);
        Bureaucrat bob("Bob", 10);

        std::cout << std::endl;
        std::cout << andrew << std::endl;
        std::cout << bob << std::endl;
        std::cout << std::endl;

        Form easyForm("Easy Form", 100, 100);
        Form hardForm("Hard Form", 20, 10);

        std::cout << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;
        std::cout << std::endl;


        bob.signForm(easyForm);
        bob.signForm(hardForm); 

        andrew.signForm(easyForm);
        andrew.signForm(hardForm); //fail

        std::cout << std::endl;
        std::cout << "Trying to create invalid forms:" << std::endl;
        std::cout << std::endl;
        Form tooHighGrade("Too High", 0, 100);
        Form tooLowGrade("Too Low", 151, 100);

    } 
    
    catch (const std::exception &e) {
        std::cout << "\nException: " << e.what() << std::endl;
    }

   return 0;
}