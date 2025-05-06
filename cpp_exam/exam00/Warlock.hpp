#pragma once

#include <string>
#include <iostream>

class Warlock {
    
    private : 
        std::string _name;
        std::string _title;

        //reference value cannot modify later once it initialized
        // const std::string & => const reference : cannot change the original value but can receive temporary, const, non-const value directly
        // std::string & => non-const reference : can change the original value but cannot receive temporary or const value directly
        Warlock();
        Warlock(const Warlock& other);
        Warlock& operator=(const Warlock& other); // should be returned in reference
    public:

        Warlock(const std::string& _name, const std::string& _title);
        ~Warlock();

        const std::string& getName() const; //we need const(the right most) in order to get called by const intance
        const std::string& getTitle() const;
        void setTitle(const std::string& newTitle);
        void introduce() const;
};