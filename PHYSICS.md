# Physics Behind the Landing Simulation

## The three forces acting on the rocket

In a 2D descent, three forces act on the rocket at any moment:

1. **Gravity** — pulls straight down, magnitude = mass × 9.81 m/s²
   (Earth's gravitational acceleration). This never changes regardless of
   the rocket's speed or orientation.

2. **Thrust** — pushes in whatever direction the engine is pointed
   (controlled by gimbal angle), magnitude depends on throttle setting.
   As fuel burns, the rocket's mass decreases, so the SAME thrust
   produces MORE acceleration over time (lighter rocket, same push).

3. **Drag** — opposes the direction of motion, magnitude increases with
   the square of velocity (roughly: drag force = 0.5 × air density ×
   velocity² × drag coefficient × cross-sectional area). This is why
   drag matters much more at high speed than low speed.

## Why mass matters and changes over time

Unlike a falling rock, a rocket's mass isn't constant — it's constantly
burning and expelling fuel. This means:
- The same thrust produces increasing acceleration as the rocket gets
  lighter
- You must track "how much fuel is left" as part of the simulation state
- Running out of fuel mid-landing is a real failure mode to simulate

## The suicide burn concept, explained simply

Imagine dropping a ball and wanting it to stop exactly at the ground with
zero speed, using only a single burst of upward force. If you apply that
force too early, you'll slow down too soon and either need to keep
hovering (wasting fuel) or you'll actually go back up. If you apply it
too late, you won't slow down in time and you'll crash.

The "suicide burn" is finding the EXACT altitude to start braking so
that your deceleration brings you to exactly zero velocity right as you
touch the ground — no earlier, no later, no wasted fuel.

The core relationship (derived from basic kinematics — the same
equations used for braking distance in a car):

**required braking distance = (current velocity)² ÷ (2 × deceleration rate)**

If your current altitude is greater than this required braking distance,
you can still afford to keep falling. Once your altitude equals this
number, it's time to start the burn.

## Why this is genuinely hard to get right

Real rockets can't apply "instant" thrust changes, sensors have delay
and noise, and the engine can't throttle infinitely — so a real
implementation must account for these imperfections, not just the ideal
math above. This is why the fault-tolerance layer of this project isn't
a side feature — it's addressing a real, core problem in actual rocket
landing systems.