

#pragma once
#include "parcer.hpp"
#define ACСURACY 0.0001


class Computor {

private:

    map<int, float> _coefficients;
    unique_ptr<Parcer> _parce_ptr;
    void    _solve_zero_degree(float coefficient);
    void    _solve_first_degree(float first_coefficient, float zero_coefficient = 0);
    void    _solve_second_degree(float third_degree, float first_coefficient = 0, float zero_coefficient = 0);
//    float   _sqrt(float number);

public:
    float   _sqrt(float number);
    bool print_polynomial_degree();
    Computor(string &&expression);
    ~Computor();
    bool    init();
    void    solve_equation();
    void __debug();
    void print_reduced_form();

};


