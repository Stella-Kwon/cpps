#include "Bureaucrat.hpp"

int main()
{

    try{
        Bureaucrat andrew("Andrew", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try{
        Bureaucrat bob("Bob", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat andrew("Andrew", 1);
    Bureaucrat bob("Bob", 150);

    std::cout << andrew << std::endl;
    std::cout << bob << std::endl;

    try
    {
        andrew.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
      bob.decrementGrade();
    } 
    catch (const std::exception &e) 
    {
      std::cerr << e.what() << std::endl;
    }

    andrew.setGrade(5);
    bob.setGrade(100);
    return 0;
}