#include "compare_functions.h"
#include <math.h>
#include <stdio.h>

bool are_equal(double number_a, double number_b) 
{
    return (is_zero(fabs(number_a- number_b))); 
}

bool is_zero(double number) 
{
    return (fabs(number) < MIN_DIFF);
}

bool are_both_nan_or_equal(const double num1, const double num2) 
{
    return isnan(num1) && isnan(num2) || are_equal(num1, num2);
}