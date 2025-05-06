#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ATarget{
    protected:
        std::string type;
    
    public:
        ATarget();
        ATarget(const std::string& type);
        virtual ~ATarget(); //abstract class or polymorphism() need the virtual destructor
        ATarget(const ATarget& other);
        ATarget& operator=(const ATarget& other);

        virtual ATarget* clone() const = 0; // const for calling from const object
        std::string getType() const;
        void getHitBySpell(const ASpell& spell) const;
};