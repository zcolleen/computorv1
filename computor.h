


#pragma once
#include <iostream>
#include <vector>
#define POLY_DEGREE 3


using namespace std;

class Computor {

private:
    vector<float> _coefficients;
    bool _check_forbidden_symbol(char s);

public:

    Computor();
    bool parce_coefficients(const string &expression);

};


