#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell{
    public:
        Fireball();
        Fireball(const Fireball& other);
        ~Fireball();
        virtual ASpell* clone() const override;
};