#include <math.h>

 
double mindiff = 0.00000001;

bool are_equal(double number_a, double number_b) {
    if (fabs(number_a - number_b) < mindiff) {
        return true;
    }
    else {
        return false;
    }

}

bool is_zero(double number_a) {
    if (fabs(number_a) < mindiff) {
        return true;
    }
    else {
        return false;
    }
}