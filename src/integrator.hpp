#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP
#include "state.hpp"
#include "physics.hpp"

// Advances the state forward by one time step, using simple integration
RocketState stepState(RocketState state, double dt)
{
    double accel = computeAcceleration(state);
    state.velocity += accel * dt;
    state.altitude += state.velocity * dt;
    state.time += dt;
    return state;
}

#endif