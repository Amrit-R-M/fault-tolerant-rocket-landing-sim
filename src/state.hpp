#ifndef STATE_HPP
#define STATE_HPP

// RocketState holds everything needed to describe the rocket at one
// instant in time. Every simulation step reads and updates one of these.
struct RocketState {
    double altitude;      // meters above ground
    double velocity;       // meters per second (negative = falling)
    double mass;            // kg, decreases as fuel burns
    double fuelRemaining;   // kg of fuel left
    double time;             // seconds since simulation start
};

// Creates a starting state for the simulation, given initial conditions
RocketState createInitialState(double startAltitude, double startVelocity, double startMass, double startFuel) {
    RocketState state;
    state.altitude = startAltitude;
    state.velocity = startVelocity;
    state.mass = startMass;
    state.fuelRemaining = startFuel;
    state.time = 0.0;
    return state;
}

#endif
