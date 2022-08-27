#include "solve_equation.h"
#include <stdio.h>
#include <assert.h>
#include "compare_functions.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

struct test_data
{
    equation_t equation;
    solution_t solution_want;
};

bool are_solutions_equal(const solution_t* solution_got, const solution_t* solution_want)
{
    assert(solution_got  != nullptr);
    assert(solution_want != nullptr);
    
    if (isnan(solution_got->x1) && isnan(solution_want->x1)) return true;
    else if (!are_equal(solution_got->x1, solution_want->x1)) return false;
    
    if (isnan(solution_got->x2) && isnan(solution_want->x2)) return true;
    else if (!are_equal(solution_got->x2, solution_want->x2)) return false; 
    
    if (solution_got->num_of_roots != solution_want->num_of_roots) return false;
    return true;
}
int main() 
{
    const test_data test[] = 
    {
        {{0, 0, 0}, {NAN, NAN, infinity_roots}}, //1
        {{0, 0, 1}, {NAN, NAN, zero_roots}},     //2
        {{0, 1, 0}, {0, NAN, one_root}},         //3
        {{1, 0, 0}, {0, NAN, one_root}},         //4
        {{1, 0, 1}, {NAN, NAN, zero_roots}},     //5
        {{1, 1, 0}, {-1, 0, two_roots}},         //6
        {{1, 1, 1}, {NAN, NAN, zero_roots}},     //7
        {{0, 1, 1}, {-1, NAN, one_root}},        //8
        {{1, 2, 3}, {NAN, NAN, zero_roots}},     //9
        {{1, 3, 2}, {-2, -1, two_roots}},        //10
    };

    solution_t solution_got; 
    int success_count = 0;
    int size_of_test = sizeof(test) / sizeof(test_data);
    
    for (int i = 0; i < size_of_test; i++) 
    {
        solution_got = {NAN, NAN, error_number_of_roots};
        solve_quadratic_equation(&test[i].equation, &solution_got);
        if (are_solutions_equal(&solution_got, &test[i].solution_want)) success_count++;
        else printf("Error in test number %d, %lf %lf %s\n", i+1, solution_got.x1, solution_got.x2);
    }

    if (success_count == size_of_test) printf(KGRN "%d / %d", success_count, size_of_test);
    else printf(KRED "%d / %d", success_count, size_of_test);
    return 0;  
}


