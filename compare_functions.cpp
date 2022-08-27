#include "compare_functions.h"

bool are_equal(double number_a, double number_b) 
{
    return (is_zero(fabs(number_a- number_b))); 
}

bool is_zero(double number) 
{
    return fabs(number) < mindiff;
}