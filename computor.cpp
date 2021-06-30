

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

void Computor::__debug()
{
    for (auto &m : _coefficients) {
        cout << m.first << " " << m.second << endl;
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
    return true;
}

void Computor::print_reduced_form()
{
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
