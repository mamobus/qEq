#include "compare_functions.h"
#include "solve_equation.h"

void solve_equation(const equation_t* equation, solution_t* solution) 
{
    double discriminant = ((equation->b * equation->b) - (4 * equation->a * equation->c)); 
    if (!is_zero(equation->a))
    {
        if (discriminant > 0) 
        {
            solution->x1 = (-equation->b - sqrt(discriminant)) / (2*equation->a);
            solution->x2 = (-equation->b + sqrt(discriminant)) / (2*equation->a);
            solution->type = 2;
        }
        else solution->type = 0;
    }
    else 
    {
        if (equation->b == 0) 
        {
            if (equation->c == 0) solution->type = 3;
            else solution->type = 0;
        }
        else 
        {
            solution->x1 = (-equation->c / equation->b);
            solution->type = 1;
        }
    }


}