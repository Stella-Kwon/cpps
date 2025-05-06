#pragma once

#include "ATarget.hpp"

class Dummy : public ATarget{
    public:
        Dummy();
        ~Dummy();
        Dummy(const Dummy& other);
        virtual ATarget *clone() const override;
};