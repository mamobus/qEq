#include <stdio.h>
#include "io_functions.h"
#include <assert.h>
#include "solve_equation.h"

void input_try(input_var_t* input_var) 
{    
    int success_input = 0;
    
    while (success_input != 3)
    {
        success_input = scanf("%lf %lf %lf", &input_var->a, &input_var->b, &input_var->c);
        
        if (success_input != 3) 
        {
            printf("invalid format. try again\n");
        }      
        fflush(stdin);
    } 
}

void print_result(answer_var_t* answer_var) 
{
    switch (answer_var->type)
    {
    case 0:
        printf("%s", "No solution"); 
        break;
    case 1:
        printf("%s %lf", "Solution:", answer_var->x1);
        break;
    case 2:
        printf("%s %lf %lf", "Solutions:", answer_var->x1, answer_var->x2);
        break;
    default:
        printf("%s", "Solution is any number");  

    }
}
// {} case io_func base value .cpp__> .h
//    assert(input_var.a != NULL);
//   assert(input_var.b != NULL);
//   assert(input_var.c != NULL);
