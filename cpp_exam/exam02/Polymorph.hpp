#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell{
    public:
        Polymorph();
        Polymorph(const Polymorph& other);
        ~Polymorph();
        virtual ASpell* clone() const override;
};