
#include "solve_equation.h"
#include "io_functions.h"
#include <stdio.h>

int main() 
{
    equation_t equation = {};
    input_equation_coefficients(&equation);
    
    solution_t solution = {};
    solve_quadratic_equation(&equation, &solution);
    
    print_solution(&solution);
    
    return 0; // должен быть СТРОГО!!!
}
