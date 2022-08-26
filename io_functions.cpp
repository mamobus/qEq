#include <stdio.h>
#include "io_functions.h"
#include <assert.h>
#include "solve_equation.h"

/**
 * @brief Input function
 * tries to read 3 coefficients from console untill succes
 * 
 * @param equation 
 */
void input_try(equation_t* equation) 
{    
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

void print_result(solution_t* solution) 
{
    switch (solution->type)
    {
        case 0:
            printf("No solution\n"); 
            break;

        case 1:
            printf("Solution: %lf\n", solution->x1);
            break;

        case 2:
            printf("%s %lf %lf", "Solutions:\n", solution->x1, solution->x2); //fix printf
            break;

        case 3:
            printf("Solution is any number\n");
            break;

        default:
            printf("error in type. Current type: %d\n", solution->type);  

    }
}
// {} case io_func base value .cpp__> .h
//    assert(equation.a != NULL);
//   assert(equation.b != NULL);
//   assert(equation.c != NULL);

