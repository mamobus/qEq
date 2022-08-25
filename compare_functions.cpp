#include "compare_functions.h"

bool are_equal(double number_a, double number_b) {
    if (fabs(number_a - number_b) < mindiff) {
        return true;
    }
    else {
        return false;
    }

}

bool is_zero(double number) {
    if (fabs(number) < mindiff) {
        return true;
    }
    else {
        return false;
    }
}