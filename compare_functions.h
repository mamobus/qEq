#ifndef COMPARE_FUNCTIONS_H
#define COMPARE_FUNCTIONS_H

#include <math.h>
/**
 * @brief Minimal difference
 * Minimal difference in two numbers to register. Is constant
 */
const double mindiff = 1e-8; // exponent

/**
 * @brief Compares two numbers
 * 
 * @param number_a 
 * @param number_b 
 * @return true if number_a and number_b have difference less then mindiff
 * @return false if number_a and number_b have difference more then mindiff
 */
bool are_equal(double number_a, double number_b);

/**
 * @brief 
 * 
 * @param number 
 * @return true  if number and zero have difference less then mindiff
 * @return false otherwise
 */
bool is_zero(double number);

#endif // COMPARE_FUNCTIONS_H