#ifndef PHYSICS_HPP
#define PHYSICS_HPP
#include "state.hpp"

const double GRAVITY = 9.81;

double computeAcceleration(RocketState state)
{
    return -GRAVITY;
}

#endif
