#include <stdio.h>
#include "io_functions.h"
#include <assert.h>
#include "solve_equation.h"

void input_equation_coefficients(equation_t* equation) 
{    
    assert(equation != nullptr);
    int success_input = 0;
    
    while (success_input != 3)
    {
        success_input = scanf("%lf %lf %lf", &equation->a, &equation->b, &equation->c);
        
        if (success_input != 3) 
        {
            printf("invalid format. try again\n");
            scanf("%*s");
        }     
    } 
}

void print_solution(solution_t* solution) 
{
    assert(solution != nullptr);
    switch (solution->num_of_roots)
    {
        case zero_roots:
            printf("No solution\n"); 
            break;

        case one_root:
            printf("Solution: %lf\n", solution->x1);
            break;

        case two_roots:
            printf("solutions: %lf, %lf", solution->x1, solution->x2); 
            break;

        case infinity_roots:
            printf("Solution is any number\n");
            break;

        default:
            printf("error in number of roots. Current number of roots: %d\n", solution->num_of_roots);

    }
}


