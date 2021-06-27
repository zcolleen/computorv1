
#include "computor.h"


Computor::Computor() : _coefficients(POLY_DEGREE, 0) {}


bool _check_forbidden_symbol(char s)
{
    if (isdigit(s) || s == '-' || s == 'X' || s == '^' || s == '=')
        return true;
    return false;
}


bool Computor::parce_coefficients(const string &expression) {

    size_t idx = 0;
    float digit = 0;
    int8_t is_negative = 1;
    int degree = 0;

    for (size_t i = 0; i < expression.size(); ++i)
    {
        if (!_check_forbidden_symbol(expression[i]))
            return false;
        if (expression[i] == 'X')
            degree = 1;
        if (expression[i] == '-')
            is_negative = -1;
        if (isdigit(expression[i])) {

            _coefficients[degree] += is_negative * stof(expression.substr(i), &idx);
            is_negative = 1;
            i = idx;
            degree = 0;
        }

    }
}

