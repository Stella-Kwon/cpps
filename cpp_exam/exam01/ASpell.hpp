#pragma once

#include <iostream>
#include <string>

class ATarget;

class ASpell{
    protected:
        std::string name;
        std::string effects;
    
    public:
        ASpell();
        ASpell(const std::string& name, const std::string& effects);
        virtual ~ASpell(); //abstract class or polymorphism() need the virtual destructor
        ASpell(const ASpell& other);
        ASpell& operator=(const ASpell& other);

        virtual ASpell* clone() const = 0; // const for calling from const object
        std::string getName() const;
        std::string getEffects() const;
        void launch(const ATarget& target) const;
};