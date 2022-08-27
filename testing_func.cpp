#include "solve_equation.h"
#include <stdio.h>
#include <assert.h>
#include "compare_functions.h"

struct test
{
    equation_t equation;
    solution_t solution_want;
};



bool are_solutions_equal(const solution_t* solution_got, const solution_t* solution_want)
{
    assert(solution_got  != nullptr);
    assert(solution_want != nullptr);

    return (solution_got->num_of_roots == solution_want->num_of_roots)  &&
          ((are_both_nan_or_equal(solution_got->x1, solution_want->x1) && are_both_nan_or_equal(solution_got->x2, solution_want->x2)) ||
           (are_both_nan_or_equal(solution_got->x1, solution_want->x2) && are_both_nan_or_equal(solution_got->x2, solution_want->x1)));
}
int main() 
{
    const test tests[] = 
    {
    //    a  b  c    x1   x2   number_of_roots   //0
        {{0, 0, 0}, {NAN, NAN, infinity_roots}}, //1
        {{0, 0, 1}, {NAN, NAN, zero_roots    }}, //2
        {{0, 1, 0}, {0,   NAN, one_root      }}, //3
        {{1, 0, 0}, {0,   NAN, one_root      }}, //4
        {{1, 0, 1}, {NAN, NAN, zero_roots    }}, //5
        {{1, 1, 0}, {-1,  0,   two_roots     }}, //6
        {{1, 1, 1}, {NAN, NAN, zero_roots    }}, //7
        {{0, 1, 1}, {-1.9999,  NAN, one_root      }}, //8
        {{1, 2, 3}, {NAN, NAN, zero_roots    }}, //9
        {{1, 3, 2}, {-2, -1,   two_roots     }}, //10
        {{1, 5, 6}, {-2,  -3,  two_roots     }}, //11
        {{1, 5, 6}, {-2,  -3,  two_roots     }}, //12
    };

    solution_t solution_got = {}; 
    int success_count = 0;
    size_t size_of_test = sizeof(tests) / sizeof(test);
    
    for (int i = 0; i < size_of_test; i++) 
    {
        solution_got = {NAN, NAN, error_number_of_roots};
        solve_quadratic_equation(&tests[i].equation, &solution_got);

        if (are_solutions_equal(&solution_got, &tests[i].solution_want)) 
        {
            success_count++;
            printf("\x1b[32mTest %d passed\n\x1b[0m", i + 1);
        }
        else 
        {
            printf("\x1b[31mTest %d failed\n", i + 1);
            printf("Equation: a = %lf, b = %lf, c = %lf; %lf*x^2 + %lf*x + %lf = 0\n", tests[i].equation.a, tests[i].equation.b, tests[i].equation.c, tests[i].equation.a, tests[i].equation.b, tests[i].equation.c);
            printf("Expected roots: ");
            switch (tests[i].solution_want.num_of_roots)
            {
            case zero_roots:
                printf("zero roots\n");
                break;
            
            case one_root:
                printf("one root: %lf\n", tests[i].solution_want.x1);
                break;
            
            case two_roots:
                printf("two roots: %lf, %lf\n", tests[i].solution_want.x1, tests[i].solution_want.x2);
                break;
            case infinity_roots:
                printf("infinite number of roots\n");
                break;
            default:
                printf("ERROR IN ERROR TESTING\n");
            }

            printf("Gotten roots: ");
            switch (solution_got.num_of_roots)
            {
            case zero_roots:
                printf("zero roots\n");
                break;
            
            case one_root:
                printf("one root: %lf\n", solution_got.x1);
                break;
            
            case two_roots:
                printf("two roots: %lf, %lf\n", solution_got.x1, solution_got.x2);
                break;
            case infinity_roots:
                printf("infinite number of roots\n");
                break;
            default:
                printf("ERROR IN ERROR TESTING\n");
            }
        } // a b c, exp roots, got roots 
    }

    if (success_count == size_of_test) printf("\x1B[32m" "%d / %d" "\x1b[0m", success_count, size_of_test);
    else printf("\x1b[31m" "%d / %d" "\x1b[0m", success_count, size_of_test); // constants of colors
    return 0;  
}
