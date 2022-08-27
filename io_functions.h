#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H
#include "solve_equation.h"

/**
 * @brief Input function
 * 
 * Tries to read 3 coefficients from console untill succes
 * 
 * @param equation Structure, that includes that coefficients
 */
void input_equation_coefficients(equation_t* equation);

/**
 * @brief Prints solution
 * 
 * Prints all the roots and their count
 * 
 * @param solution Structure structure, includes roots and their count 
 */
void print_solution(solution_t* solution); 

#endif //IO_FUNCTIONS_H