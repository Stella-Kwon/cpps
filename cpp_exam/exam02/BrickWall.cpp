#include "BrickWall.hpp"

BrickWall::BrickWall():ATarget("Inconspicuous Red-brick Wall"){};
BrickWall::~BrickWall(){};
BrickWall::BrickWall(const BrickWall& other):ATarget(other){};
ATarget * BrickWall::clone() const { 
    return new BrickWall(*this); 
}