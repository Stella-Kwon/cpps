#pragma once

#include "AForm.hpp"

class Intern {

    public:
        Intern();
        Intern(const Intern& other);
        Intern &operator=(const Intern &other);
        ~Intern();
    
        AForm *makeForm(std::string const &formName, const std::string &target);



      private:
      //make function pointer is called FormCreator 
      //that has const string & param
      //and returns AForm*
        typedef AForm* (Intern::*FormCreator)(const std::string &) const;

        AForm *createShrubberyForm(std::string const &target) const;
        AForm *createRobotomyForm(std::string const &target) const;
        AForm *createPresidentialForm(std::string const &target) const;

        //all instance will share this value
        static const int NUM_FORMS = 3;
        static const std::string formNames[NUM_FORMS];
};

