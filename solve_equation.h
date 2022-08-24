int solve_equation(input_var_t input_var, answer_var_t answer_var);

struct input_var_t
{
    double a = NAN, b = NAN, c = NAN;
};
struct answer_var_t
{
    double x1 = NAN, x2 = NAN;
    int type = -1;
};