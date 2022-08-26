
#include "solve_equation.h"
#include "io_functions.h"
#include <stdio.h>

int main() 
{
    equation_t equation = {};
    input_try(&equation);
    
    solution_t solution = {};
    solve_equation(&equation, &solution);
    
    print_result(&solution);
    
    return 0; // должен быть СТРОГО!!!
}
    

//засунуть type in enum 
//переименовать в нормальное
//очистка ввода через стирание строки посимвольно getchar
//документация 