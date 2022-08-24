int solve_equation(double a, double b, double c, double* x1, double* x2);

struct input_var_t
{
    double a = NAN, b = NAN, c = NAN;
};
struct answer_var_t
{
    double x1 = NAN, x2 = NAN;
    int type = -1;
};