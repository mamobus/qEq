#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include <math.h>

struct equation_t
{
    double a = NAN, b = NAN, c = NAN;
};
struct solution_t
{
    double x1 = NAN, x2 = NAN;
    int type = -1;
    enum num_of_roots {zero, one, two, infinite};
};

void solve_equation(const equation_t* equation, solution_t* solution);

#endif // SOLVE_EQUATION_H