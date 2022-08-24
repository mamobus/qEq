#include "solve_equation.h"
#include "io_functions.h"
#include <stdio.h>
#include <cmath>


int main() 
{
    double fsdf = NAN;
    input_var_t input_var = {};
    answer_var_t answer_var = {};

    input_try(&input_var);

    printf("based\n");

    input_try(&a, &b, &c);
    
    type = solve_equation(a, b, c, &x1, &x2);
    
    print_result ( x1, x2, type );

    scanf("%d", type);
}

