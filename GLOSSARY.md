# Glossary — Key Terms Explained From Scratch

## Rocket dynamics terms

**State** — a snapshot of everything you need to know about the rocket at
one instant in time: its position, velocity, mass, and orientation. Every
simulation step calculates a new state from the previous one.

**Thrust** — the force pushing the rocket, produced by the engine burning
fuel and expelling it downward at high speed. More thrust = more upward/
directional push, but it also burns fuel, reducing the rocket's mass over
time.

**Drag** — a force from air resistance that opposes the rocket's motion
(pushes against whichever direction it's moving). Depends on speed and
air density — stronger at high speed, weaker at high altitude where air
is thinner.

**Gravity** — the constant downward pull on the rocket. Unlike thrust and
drag, gravity doesn't depend on the rocket's speed or fuel — it's always
present, always pulling down.

## Guidance, Navigation, Control (GNC) — three separate jobs

**Guidance** — decides WHERE the rocket should be right now, given where
it wants to end up (a soft landing at a target point). Think of this as
"the plan."

**Navigation** — figures out where the rocket ACTUALLY is right now, using
sensor readings (altitude, velocity, orientation). This can be wrong if
sensors are faulty — that's where fault tolerance becomes relevant.

**Control** — takes the gap between "where guidance says I should be" and
"where navigation says I actually am," and computes the actual thrust/
gimbal commands to close that gap.

These three are often confused as one thing, but they're genuinely
separate problems, usually built as separate pieces of software.

## Fault tolerance terms

**Sensor fault** — a sensor reporting incorrect data, either due to noise
(random small errors), bias (consistently wrong by a fixed amount), or
dropout (no reading at all).

**Actuator fault** — a component that responds to commands (like a gimbal
motor) failing to move correctly, moving too slowly, or getting stuck.

**Fault detection** — the system noticing something is wrong, usually by
comparing what a sensor SAYS against what a physics model PREDICTS it
should say. A large mismatch suggests a fault.

**Fault-tolerant** — a system that keeps functioning safely even after a
fault occurs, rather than simply failing. This usually means detecting
the fault AND adapting behavior in response, not just detecting it.

## Simulation/numerical terms

**RK4 (Runge-Kutta 4th order)** — a method for numerically calculating how
a system changes over small time steps, more accurate than simpler
methods (like just multiplying velocity by time) because it samples the
rate of change multiple times within each step instead of just once.

**Monte Carlo simulation** — running the same simulation many times with
randomized starting conditions (wind, sensor noise, fault timing) to see
how often the system succeeds vs fails, producing statistics rather than
a single pass/fail result from one run.