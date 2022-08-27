#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include <math.h>

/**
 * @brief Enum variable, means number of roots 
 * 
 */
enum num_of_roots_t {zero_roots, one_root, two_roots, infinity_roots, error_number_of_roots};

/**
 * @brief Stores equation coefficients a, b, c
 * 
 */
struct equation_t
{
    double a = NAN, b = NAN, c = NAN;
};

/**
 * @brief Stores result roots and their count 
 * 
 */
struct solution_t
{
    double x1 = NAN, x2 = NAN;
//    int type = -1;
    num_of_roots_t num_of_roots = error_number_of_roots; 
};

/**
 * @brief Solves quadratic equation 
 * Solves quadratic equation, but only if it is mathematically possible
 * @param equation Condition structure, includes 3 coefficients: a, b, c of a*x^2 + b*x + c = 0 equation
 * @param solution Solution structure, includes roots and their count
 */
void solve_quadratic_equation(const equation_t* equation, solution_t* solution);

/**
 * @brief Solves linear equation 
 * Solves linear equation, but only if it is mathematically possible
 * @param equation Condition structure, includes 3 coefficients: a, b, c of a*x^2 + b*x + c = 0 equation
 * @param solution Solution structure, includes roots and their count
 */
void solve_linear_equation(const equation_t* equation, solution_t* solution);
#endif // SOLVE_EQUATION_H