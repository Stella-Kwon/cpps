#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}
Dummy::~Dummy(){};
Dummy::Dummy(const Dummy &other):ATarget(other){};
ATarget* Dummy::clone()const{
    return new Dummy(*this);
}