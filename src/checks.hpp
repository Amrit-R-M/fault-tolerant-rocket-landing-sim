#ifndef CHECKS_HPP
#define CHECKS_HPP
#include "state.hpp"

// Returns true once the rocket has reached the ground
bool hasLanded(RocketState state)
{
    return state.altitude <= 0;
}

#endif