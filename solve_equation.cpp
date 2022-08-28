#include "compare_functions.h"
#include "solve_equation.h"
#include "assert.h"

void solve_linear_equation(const equation_t* equation, solution_t* solution) 
{
    assert(equation != nullptr);
    assert(solution != nullptr); 
    assert(equation->a == 0);

    if (is_zero(equation->b)) 
    {   
        if (equation->c == 0) solution->num_of_roots = INFINITY_ROOTS;
        else solution->num_of_roots = ZERO_ROOTS;
    }
    else 
    {
        solution->x1 = (-equation->c / equation->b);
        solution->num_of_roots = ONE_ROOT;
    }
}

void solve_quadratic_equation(const equation_t* equation, solution_t* solution) 
{
    assert(equation != nullptr);
    assert(solution != nullptr);

    if (is_zero(equation->a))
    {    
        solve_linear_equation(equation, solution);
        return;
    }
    
    double discriminant = ((equation->b * equation->b) - (4 * equation->a * equation->c));
    if (is_zero(discriminant))
    {
        solution->x1 = (-equation->b - sqrt(discriminant)) / (2 * equation->a);
        solution->num_of_roots = ONE_ROOT;
    }
    else if (discriminant > 0) //discr is zero
    {
        solution->x1 = (-equation->b - sqrt(discriminant)) / (2 * equation->a);
        solution->x2 = (-equation->b + sqrt(discriminant)) / (2 * equation->a);
        solution->num_of_roots = TWO_ROOTS;
    }
    else solution->num_of_roots = ZERO_ROOTS;
}