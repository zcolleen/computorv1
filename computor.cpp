

#include "computor.hpp"


Computor::Computor(string &&expression) : _parce_ptr(make_unique<Parcer>(move(expression))) {}

Computor::~Computor() = default;

bool Computor::init()
{
    if (!_parce_ptr->parce())
        return false;
    _coefficients = _parce_ptr->get_coefficients();
    return true;
}

void Computor::_solve_zero_degree(float coefficient)
{
    if (coefficient == 0)
        cout << "Equation has infinite solutions" << endl;
    else
        cout << "Equation has no solutions" << endl;
}

float Computor::_sqrt(float number)
{
    float _sqrt = number / 2;

    while (_sqrt * _sqrt - number > ACСURACY || _sqrt * _sqrt - number < -ACСURACY) {
        _sqrt = (_sqrt + number / _sqrt) / 2.0;
    }

    return _sqrt;
}

void Computor::_solve_second_degree(float second_coefficient, float first_coefficient, float zero_coefficient)
{
    float discriminant = first_coefficient * first_coefficient - 4 * second_coefficient * zero_coefficient;

    if (discriminant == 0) {
        float solution = (-1) * first_coefficient / (2 * second_coefficient);
        if (solution == 0)
            cout << "Discriminant is zero, the only solution is: " << endl << "0" << endl;
        else
            cout << "Discriminant is zero, the only solution is: " << endl << solution << endl;
    }
    else if (discriminant > 0) {
        float root = _sqrt(discriminant);
        cout << "Discriminant is strictly positive, the two solutions are: " << endl;
        cout << ((-1) * first_coefficient - root) / (2 * second_coefficient) << endl;
        cout << ((-1) * first_coefficient + root) / (2 * second_coefficient) << endl;
    }
    else {
        float root = _sqrt((-1) * discriminant);
        cout << "Discriminant is negative, the two solutions are: " << endl;
        cout << ((-1) * first_coefficient) / (2 * second_coefficient);
        if (second_coefficient < 0)
            cout << "+" << - root / (2 * second_coefficient) << "i" << endl;
        else
            cout << - root / (2 * second_coefficient) << "i" << endl;
        cout << ((-1) * first_coefficient) / (2 * second_coefficient);
        if (second_coefficient < 0)
            cout << root / (2 * second_coefficient) << "i" << endl;
        else
            cout << "+" << root / (2 * second_coefficient) << "i" << endl;
    }
}

void Computor::_solve_first_degree(float first_coefficient, float zero_coefficient)
{
    cout << "The solution is: " << endl;
    float solution = (-1) * zero_coefficient / first_coefficient;
    if (solution == 0)
        cout << "0" << endl;
    else
        cout << solution << endl;
}


void Computor::solve_equation()
{
    auto max_degree = _coefficients.rbegin();
    std::map<float, float>::reverse_iterator zero_degree;

    switch ((int )max_degree->first) {
        case ZERO_DEGREE:
            _solve_zero_degree(max_degree->second);
            break;
        case FIRST_DEGREE:
            zero_degree = ++_coefficients.rbegin();
            if (zero_degree == _coefficients.rend())
                _solve_first_degree(max_degree->second, 0);
            else
                _solve_first_degree(max_degree->second, (++max_degree)->second);
            break;
        case SECOND_DEGREE:
            auto second_degree = ++_coefficients.rbegin();
            if (second_degree->first == 1) {
                if ((++second_degree) == _coefficients.rend())
                    _solve_second_degree(max_degree->second, second_degree->second, 0);
                else
                    _solve_second_degree(max_degree->second, second_degree->second, (second_degree)->second);
            }
            else {
                if (second_degree == _coefficients.rend())
                    _solve_second_degree(max_degree->second, 0, 0);
                else
                    _solve_second_degree(max_degree->second, 0, second_degree->second);
            }
            break;
    }
}

bool Computor::print_polynomial_degree()
{
    auto it = _coefficients.rbegin();
    cout << "Polynomial degree: " << it->first << endl;
    if (it->first > 2) {
        cout << "The polynomial degree is strictly greater than 2, I can't solve." << endl;
        return false;
    }
    for (; it != _coefficients.rend(); ++it) {
        if (it->first != (int )it->first) {
            cout << "The polynomial degree is non whole, I can't solve." << endl;
            return false;
        }
    }
    return true;
}

void Computor::print_reduced_form()
{
    cout << "Reduced form: ";
    for (auto it = _coefficients.begin(); it != _coefficients.end(); ++it)
    {
        if (it->second < 0)
            cout << "- " << (-1) * it->second;
        else {
            if (it == _coefficients.begin())
                cout << it->second;
            else
                cout << "+ " << it->second;
        }
        cout << " * X^" << it->first << " ";
    }
    cout << "= 0" << endl;
}
