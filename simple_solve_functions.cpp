#include <math.h>
#include <assert.h>
#include "simple_solve_functions.h"
#include "compare_functions.h"

void solve_complete_quad(const input_var_t* input_var, answer_var_t* answer_var) 
{
    assert(input_var != nullptr);
    assert(answer_var != nullptr);

    double discriminant = ((input_var->b*input_var->b) - (4*input_var->a*input_var->c)); 
    assert(discriminant >= 0);
    assert(!is_zero(input_var->a));
    answer_var->x1 = (-input_var->b - sqrt(discriminant) ) / (2 * input_var->a);
    answer_var->x2 = (-input_var->b + sqrt(discriminant) ) / (2 * input_var->a);
}

void solve_incomplete_quad(const input_var_t* input_var, answer_var_t* answer_var) 
{
    assert(input_var != nullptr);
    assert(answer_var != nullptr);
    assert(!is_zero(input_var->a));
    answer_var->x1 = -sqrt(-input_var->c / input_var->a);
    answer_var->x2 =  sqrt(-input_var->c / input_var->a);
}

void solve_linear(const input_var_t* input_var, answer_var_t* answer_var) 
{
    assert(input_var);
    assert(answer_var);
    assert(is_zero(input_var->a));
    
    if (is_zero(input_var->b)) 
        {
            if (is_zero(input_var->c))
            answer_var->type = 3;
        }
        else 
        {
            answer_var->x1= (-input_var->c / input_var->b);
            answer_var->type = 1;
        }
}