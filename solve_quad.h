#include <math.h>

void solve_full_quad(double a, double b, double c, double* x1, double* x2) {
    double d = ((b*b) - (4*a*c)); 
    *x1 = (-b - sqrt(d) ) / (2 * a);
    *x2 = (-b + sqrt(d) ) / (2 * a);
}

void solve_not_full_quad(double a, double c, double* x1, double* x2) {

    *x1 = -sqrt(-c / a);
    *x2 = sqrt(-c / a);
    
}