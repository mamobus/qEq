#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H
#include "solve_equation.h"

enum continue_param
{
    EXIT     = 0,
    CONTINUE = 1,
};

/**
 * @brief Input function
 * 
 * Tries to read 3 coefficients from console untill succes
 * 
 * @param equation Structure, that includes that coefficients
 */
continue_param input_equation_coefficients(equation_t* equation);

/**
 * @brief Prints solution
 * 
 * Prints all the roots and their count
 * 
 * @param solution Structure structure, includes roots and their count 
 */
void print_solution(solution_t* solution); 

#endif //IO_FUNCTIONS_H