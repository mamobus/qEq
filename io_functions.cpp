#include <stdio.h>
#include "io_functions.h"
#include <assert.h>
#include "solve_equation.h"

/**
 * @file
 * @brief Input function
 * Tries to read 3 coefficients from console untill succes
 * 
 * @param equation Structure, that consists of that coefficints
 */
void input_equation_coefficients(equation_t* equation) 
{    
    // ass
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
    //жопа
    switch (solution->num_of_roots)
    { //это временно 
        case zero_roots:
            printf("No solution %lf %lf\n", solution->x1, solution->x2); 
            break;

        case one_root:
            printf("Solution: %lf %lf\n", solution->x1, solution->x2);
            break;

        case two_roots:
            printf("%s %lf %lf", "Solutions:\n", solution->x1, solution->x2); //fix printf
            break;

        case infinity_roots:
            printf("Solution is any number %lf %lf\n", solution->x1, solution->x2);
            break;

        default:
            printf("error in number of roots. Current number of roots: %d\n", solution->num_of_roots);

    }
}
// {} case io_func base value .cpp__> .h
//    assert(equation.a != NULL);
//   assert(equation.b != NULL);
//   assert(equation.c != NULL);

