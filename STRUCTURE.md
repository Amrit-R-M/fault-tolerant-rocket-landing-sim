# Project Structure

## Proposed folder layout

fault-tolerant-rocket-landing-sim/
├── src/
│   ├── main.cpp          - entry point, runs the simulation loop
│   ├── state.hpp          - RocketState struct (position, velocity, mass, etc.)
│   ├── physics.hpp/.cpp   - RK4 integrator, force calculations
│   ├── guidance.hpp/.cpp  - suicide burn / descent guidance logic
│   ├── control.hpp/.cpp   - PID controller, translates guidance to thrust commands
│   ├── faults.hpp/.cpp    - fault injection models (sensor noise, actuator faults)
│   └── detection.hpp/.cpp - residual-based fault detection
├── tests/                 - test scenarios / expected outcomes
├── PLAN.md
├── RESEARCH.md
├── PHYSICS.md
├── GLOSSARY.md
└── README.md

## Why this separation

Each file maps to one distinct responsibility from the GNC breakdown in
GLOSSARY.md - physics, guidance, control, and fault detection are kept
separate so each piece can be built, tested, and understood independently
before wiring them together in main.cpp.