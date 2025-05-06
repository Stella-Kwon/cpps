#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
    
    private : 
        std::string _name;
        std::string _title;
        std::unordered_map<std::string, ASpell*> _spellBook;

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

        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spellName);
        void launchSpell(const std::string& spellName, const ATarget& target);
};