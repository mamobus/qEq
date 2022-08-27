#ifndef COMPARE_FUNCTIONS_H
#define COMPARE_FUNCTIONS_H

#include <math.h>
/**
 * @brief Minimal difference
 * 
 * Minimal difference in two numbers to register. Is constant
 */
const double mindiff = 1e-8; // exponent

/**
 * @brief Compares two numbers
 * 
 * @param number_a 
 * @param number_b 
 * 
 * @return true if number_a and number_b have difference less then mindiff
 * @return false otherwise
 */
bool are_equal(const double number_a,const double number_b);

/**
 * @brief 
 * 
 * @param number 
 * @return true  if number and zero have difference less then mindiff
 * @return false otherwise
 */
bool is_zero(double number);

/**
 * @brief Compares two nums
 * 
 * Compares two nums, but also returns true if both are NAN
 * 
 * @param num1 first num
 * @param num2 second num
 * 
 * @return true if both are equal or both are NAN
 * @return false otherwise
 */
bool are_both_nan_or_equal(const double num1, const double num2);

#endif // COMPARE_FUNCTIONS_H
