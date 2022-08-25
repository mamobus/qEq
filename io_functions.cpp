#include <stdio.h>
#include "io_functions.h"
#include <assert.h>
#include "solve_equation.h"

/**
 * @brief Input function
 * tries to read 3 coefficients from console untill succes
 * 
 * @param input_var 
 */
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
        fflush(stdin); // getchar
    } 
}

void print_result(answer_var_t* answer_var) 
{
    switch (answer_var->type)
    {
        case 0:
            printf("No solution\n"); 
            break;

        case 1:
            printf("Solution: %lf\n", answer_var->x1);
            break;

        case 2:
            printf("%s %lf %lf", "Solutions:\n", answer_var->x1, answer_var->x2); //fix printf
            break;

        case 3:
            printf("Solution is any number\n");
            break;

        default:
            printf("error in type. Current type: %d\n", answer_var->type);  

    }
}
// {} case io_func base value .cpp__> .h
//    assert(input_var.a != NULL);
//   assert(input_var.b != NULL);
//   assert(input_var.c != NULL);

//засунуть type in enum 
//переименовать в нормальное
//очистка ввода через стирание строки посимвольно getchar
//документация 
//вернуть simple_funcs в solve_eq 