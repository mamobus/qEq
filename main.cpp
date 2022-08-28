
#include "solve_equation.h"
#include "io_functions.h"
#include <stdio.h>

int main() 
{
    equation_t equation = {};
    if (input_equation_coefficients(&equation) == EXIT)
        return 0;

    solution_t solution = {};
    solve_quadratic_equation(&equation, &solution);
    
    print_solution(&solution);

    return 0;
}
