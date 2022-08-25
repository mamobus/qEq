#ifndef SIMPLE_SOLVE_FUNCTION_H
#define SIMPLE_SOLVE_FUNCTION_H
#include "solve_equation.h"

void solve_full_quad(const input_var_t* input_var, answer_var_t* answer_var);
void solve_not_full_quad(const input_var_t* input_var, answer_var_t* answer_var);
void solve_linear(const input_var_t* input_var, answer_var_t* answer_var);
//double calculate_d();
#endif //SIMPLE_SOLVE_FUNCTION_H