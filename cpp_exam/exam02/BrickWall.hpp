#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget{
    public:
        BrickWall();
        ~BrickWall();
        BrickWall(const BrickWall& other);
        virtual ATarget* clone() const override;
};