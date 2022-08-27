#include "compare_functions.h"
#include <math.h>
#include <stdio.h>

bool are_equal(double number_a, double number_b) 
{
    return (is_zero(fabs(number_a- number_b))); 
}

bool is_zero(double number) 
{
    return fabs(number) < mindiff;
}

bool are_both_nan_or_equal(const double num1, const double num2) 
{
    if (isnan(num1) && isnan(num2)) return true;
    else if (are_equal(num1, num2)) return true;
    return false;
}