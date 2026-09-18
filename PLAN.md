# Fault-Tolerant Rocket Landing Sim — Project Plan

## Goal
Build a 2D powered-descent landing simulation with fault injection and
adaptive guidance, to understand how real rocket landing GNC (guidance,
navigation, control) systems work — modeled loosely on public SpaceX/NASA
powered descent guidance approaches.

## Phases

### Phase 1: Core Physics (Day 1-2)
- 2D rigid body dynamics: position, velocity, mass, orientation
- Forces: gravity, thrust, drag
- RK4 numerical integrator
- Milestone: rocket falls under gravity alone, physics looks correct

### Phase 2: Baseline Guidance + Control (Day 2-4)
- Suicide burn / gravity turn approximation for guidance
- PID controller for thrust vector + throttle
- Milestone: rocket lands softly under ideal conditions, no faults

### Phase 3: Fault Injection (Day 4-6)
- Sensor fault models: noisy altitude, dropout, biased readings
- Actuator fault models: partial gimbal stuck, thrust variance
- Milestone: faults are injectable and logged, system doesn't yet compensate

### Phase 4: Fault Detection + Adaptive Guidance (Day 6-9)
- Residual-based fault detection (compare expected vs actual sensor behavior)
- Online re-planning when a fault is detected
- Milestone: system detects a fault and adapts, landing success rate improves vs no adaptation

### Phase 5: Dispersion Analysis (Day 9-12)
- Monte Carlo runs: randomized initial conditions + fault probabilities
- Output: landing success rate, touchdown velocity distribution, fuel margin stats
- Milestone: a results dashboard/report showing system reliability under uncertainty

## What makes this project distinct
Most landing sims stop at "physics + controller, lands once." This one adds
fault detection, adaptive re-planning, and statistical validation via Monte
Carlo dispersion analysis — mirroring how real GNC systems are actually
validated before flight.