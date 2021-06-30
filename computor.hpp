

#pragma once
#include "parcer.hpp"

class Computor {

private:

    map<int, float> _coefficients;
    unique_ptr<Parcer> _parce_ptr;

public:

    bool print_polynomial_degree();
    Computor(string &&expression);
    ~Computor();
    bool    init();
    void __debug();
    void print_reduced_form();

};


