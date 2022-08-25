#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include <math.h>
struct input_var_t
{
    double a = NAN, b = NAN, c = NAN;
};
struct answer_var_t
{
    double x1 = NAN, x2 = NAN;
    int type = -1;
};

void solve_equation(const input_var_t* input_var, answer_var_t* answer_var);

#endif // SOLVE_EQUATION_H