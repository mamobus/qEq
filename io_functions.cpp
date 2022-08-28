#include <stdio.h>
#include "io_functions.h"
#include <assert.h>
#include "solve_equation.h"
#include <stdlib.h>

continue_param input_equation_coefficients(equation_t* equation) 
{    
    assert(equation != nullptr);
    int success_input = 0;
    
    printf("Enter equation coefficients in the next order: a, b, c. 'q' for exit\n");
    
    while (success_input != 3)
    {
        success_input = scanf("%lf %lf %lf", &equation->a, &equation->b, &equation->c);

        if (getchar() == 'q')
            return EXIT;
        
        if (success_input == 3)
            return CONTINUE;
        
        printf("invalid format. try again\n");

        while (getchar() != '\n')
            ;
    } 
    return CONTINUE;
} 

void print_solution(const solution_t* solution) 
{
    assert(solution != nullptr);
    switch (solution->num_of_roots)
    {
        case ZERO_ROOTS:
            printf("No solution\n"); 
            break;

        case ONE_ROOT:
            printf("Solution: %lg\n", solution->x1);
            break;

        case TWO_ROOTS:
            printf("solutions: %lg, %lg", solution->x1, solution->x2); 
            break;

        case INFINITY_ROOTS:
            printf("Solution is any number\n");
            break;

        default:
            printf("error in number of roots. Current number of roots: %d\n", solution->num_of_roots);
    }
}


//printf как будто выполняется не сразу, а поочерёдно посимвольно вместе с while