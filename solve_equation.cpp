#include "compare_functions.h"
#include "solve_linear.h"
#include "solve_quad.h"
#include "solve_equation.h"

int solve_equation(double a, double b, double c, double* x1, double* x2) {
    double d = ((b*b) - (4*a*c)); 
    
    if (is_zero(a)) {
        if (is_zero(b)) {
            if (is_zero(c))
            return 0;
        }
        else {
            solve_linear(b, c, x1);
            return 1;
        }
    }
    else if (is_zero(b)) {
        if ( (-c / a) > 0 ) {
            solve_not_full_quad(a, c, x1, x2);
            return 2;
        }

    }
    else if (is_zero(c)) {
        *x1 = 0;
        *x2 = -b / a; 
        return 2;
    }
    else if (d >= 0) {
        solve_full_quad(a, b, c, x1, x2);
        return 2;
    }
return 3;
}                                                                                               
