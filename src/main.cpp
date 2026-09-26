#include <iostream>
#include "state.hpp"
#include "physics.hpp"
#include "integrator.hpp"
#include "checks.hpp"
using namespace std;

int main()
{
    RocketState state = {1000.0, 0.0, 500.0, 0.0};
    double dt = 0.5;

    while (!hasLanded(state))
    {
        state = stepState(state, dt);
        cout << "t=" << state.time << " alt=" << state.altitude << endl;
    }

    return 0;
}