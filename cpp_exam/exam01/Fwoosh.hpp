#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell{
    public:
        Fwoosh();
        ~Fwoosh();
        Fwoosh(const Fwoosh &other);
        virtual ASpell *clone() const override;
};