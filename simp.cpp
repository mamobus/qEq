#include "solve_equation.h"
#include "io_functions.h"
#include <stdio.h>

int main() 
{
    input_var_t input_var = {};
    answer_var_t answer_var = {};

    input_try(&input_var);
    
    solve_equation(&input_var, &answer_var);
    
    print_result (&answer_var);
}

// 