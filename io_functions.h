#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H
#include "solve_equation.h"

/**
 * @brief Takes coefficients from console
 * function that takes your a, b, c coefficients directly from the console. Tries again till sucessfull 
 * 
 * @param equation 
 */
void input_equation_coefficients(equation_t* equation);

/**
 * @brief Prints solution
 * 
 * @param solution TEST THE PARAM
 */
void print_solution(solution_t* solution); 

#endif //IO_FUNCTIONS_H