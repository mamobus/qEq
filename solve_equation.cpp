#include "compare_functions.h"
#include "solve_equation.h"
#include "simple_solve_functions.cpp"

void solve_equation(const input_var_t* input_var, answer_var_t* answer_var) 
{
    double discriminant = ((input_var->b * input_var->b) - (4 * input_var->a * input_var->c)); 
    answer_var->type = 0;
    if (is_zero(input_var->a)) 
    {
        solve_linear(input_var, answer_var); 
    }

    // discriminant = ...

    /*
    if (isZero(d)) {
        
    }
    */

    else if (is_zero(input_var->b)) 
    {
        if ( (-input_var->c / input_var->a) > 0) 
        {
            solve_incomplete_quad(input_var, answer_var);
            answer_var->type = 2;
        }

    }
    else if (is_zero(input_var->c)) 
    {
        answer_var->x1 = 0;
        answer_var->x2 = -input_var->b / input_var->a; 
        answer_var->type = 2;
    }
    else if (discriminant >= 0) 
    {
        solve_complete_quad(input_var, answer_var);
        answer_var->type = 2;
    }
}                                                                                               
