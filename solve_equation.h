#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include <math.h>

enum num_of_roots_t {zero_roots, one_root, two_roots, infinity_roots, error_number_of_roots};

struct equation_t
{
    double a = NAN, b = NAN, c = NAN;
};

struct solution_t
{
    double x1 = NAN, x2 = NAN;
//    int type = -1;
    num_of_roots_t num_of_roots = error_number_of_roots; 
};

void solve_quadratic_equation(const equation_t* equation, solution_t* solution);

#endif // SOLVE_EQUATION_H