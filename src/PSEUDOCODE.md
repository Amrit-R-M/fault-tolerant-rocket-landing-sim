# Pseudocode — Main Simulation Loop

## High-level flow

    state = createInitialState(altitude, velocity, mass, fuel)

    while state.altitude > 0:
        # 1. Navigation - read sensors (with possible faults injected)
        sensedAltitude = readAltitudeSensor(state, faultModel)
        sensedVelocity = readVelocitySensor(state, faultModel)

        # 2. Fault detection - check if sensor readings look wrong
        if detectFault(sensedAltitude, predictedAltitude):
            flagFault()
            sensedAltitude = fallbackEstimate()

        # 3. Guidance - decide what velocity we SHOULD have right now
        targetVelocity = computeSuicideBurnTarget(sensedAltitude)

        # 4. Control - compute thrust needed to reach target velocity
        thrustCommand = pidController(targetVelocity, sensedVelocity)

        # 5. Physics - apply forces, step simulation forward using RK4
        state = rk4Step(state, thrustCommand, dt)

        # 6. Logging - record this step for later analysis
        logState(state)

    # Simulation ends when altitude reaches 0
    reportResults(state)  # touchdown velocity, fuel remaining, success/fail

## Notes
- dt = simulation time step (e.g. 0.01 seconds)
- rk4Step() will implement the RK4 integrator described in PHYSICS.md
- computeSuicideBurnTarget() implements the braking-distance formula from PHYSICS.md
- This pseudocode intentionally omits real fault probability logic for now -
  that gets fleshed out once faults.hpp exists
  