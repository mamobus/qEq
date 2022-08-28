#include "solve_equation.h"
#include <stdio.h>
#include <assert.h>
#include "compare_functions.h"
#include "testing_func.h"

bool are_solutions_equal(const solution_t* solution_got, const solution_t* solution_want)
{
    assert(solution_got  != nullptr);
    assert(solution_want != nullptr);

    return (solution_got->num_of_roots == solution_want->num_of_roots) &&
          ((are_both_nan_or_equal(solution_got->x1, solution_want->x1) && are_both_nan_or_equal(solution_got->x2, solution_want->x2)) ||
           (are_both_nan_or_equal(solution_got->x1, solution_want->x2) && are_both_nan_or_equal(solution_got->x2, solution_want->x1)));
}

void print_test_result(const solution_t* solution)
{
    switch (solution->num_of_roots)
    {
        case ZERO_ROOTS:
            printf("zero roots\n");
            break;
        
        case ONE_ROOT:
            printf("one root : %lg\n", solution->x1);
            break;
        
        case TWO_ROOTS:
            printf("two roots: %lg, %lg\n", solution->x1, solution->x2);
            break;

        case INFINITY_ROOTS:
            printf("infinite number of roots\n");
            break;

        default:
            printf("ERROR IN ERROR TESTING\n");
            break;
    }
}

int main() 
{
    const test tests[] = 
    {
    //    a  b  c    x1   x2   number_of_roots   //0
        {{0, 0, 0}, {NAN, NAN, INFINITY_ROOTS}}, //1
        {{0, 0, 1}, {NAN, NAN, ZERO_ROOTS    }}, //2
        {{0, 1, 0}, {0,   NAN, ONE_ROOT      }}, //3
        {{1, 0, 0}, {0,   NAN, ONE_ROOT      }}, //4
        {{1, 0, 1}, {NAN, NAN, ZERO_ROOTS    }}, //5
        {{1, 1, 0}, {-1,  0,   TWO_ROOTS     }}, //6
        {{1, 1, 1}, {NAN, NAN, ZERO_ROOTS    }}, //7
        {{0, 1, 1}, {-1.9999,  NAN, ONE_ROOT }}, //8
        {{1, 2, 3}, {NAN, NAN, ZERO_ROOTS    }}, //9
        {{1, 3, 2}, {-2, -1,   TWO_ROOTS     }}, //10
        {{1, 5, 6}, {-2,  -3,  TWO_ROOTS     }}, //11
        {{1, 5, 6}, {-2,  -3,  TWO_ROOTS     }}, //12
    };

    solution_t solution_got = {}; 
    int success_count = 0;
    size_t size_of_test = sizeof(tests) / sizeof(test);
    
    for (size_t i = 0; i < size_of_test; i++)
    {
        solution_got = {NAN, NAN, ERROR_NUMBER_OF_ROOTS};
        solve_quadratic_equation(&tests[i].equation, &solution_got);

        if (are_solutions_equal(&solution_got, &tests[i].solution_want)) 
        {
            success_count++;
            printf("%sTest %d passed%s\n", ANSI_COLOR_GREEN, i + 1, ANSI_COLOR_RESET);
        }
        else 
        {
            printf("%sTest %d failed\n", ANSI_COLOR_RED, i + 1); 
            printf("Equation: a = %lg, b = %lg, c = %lg\n", tests[i].equation.a, tests[i].equation.b, tests[i].equation.c);

            printf("Expected roots: ");
            print_test_result(&tests[i].solution_want);

            printf("Gotten roots  : ");
            print_test_result(&solution_got);
            printf(ANSI_COLOR_RESET);
        }
    }

    if (success_count == size_of_test) printf("%s%d / %d tests passed%s", ANSI_COLOR_GREEN, success_count, size_of_test, ANSI_COLOR_RESET);
    else printf("%s%d / %d tests passed%s", ANSI_COLOR_RED, success_count, size_of_test, ANSI_COLOR_RESET);
    return 0;  
}
