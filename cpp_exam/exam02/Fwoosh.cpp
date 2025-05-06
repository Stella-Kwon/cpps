#include "Fwoosh.hpp"

Fwoosh::Fwoosh():ASpell("Fwoosh", "fwooshed") {}
Fwoosh::~Fwoosh(){};
Fwoosh::Fwoosh(const Fwoosh& other):ASpell(other){};
ASpell* Fwoosh::clone()const{
    return new Fwoosh(*this);
}