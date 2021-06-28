


#pragma once
#include <iostream>
#include <vector>
#include <map>
#define SYNTAX_ERROR 0


using namespace std;

class Parcer {

private:
    map<int, float> _coefficients;
    string _expression;
    bool _check_forbidden_symbol(char s);
    void _split(vector<string> &result, const string &input, const string &separators);
    bool _check_for_separator(const char &c, const string &separators);
    bool _parce_coefficients(string &str);
    bool _validate(bool *validation, int &degree, const string &str, int idx);
    bool _write_into_map(const string &str, size_t idx, int degree, float num);
    void _trim(string &str);
    bool _print_error(int error_num);

public:

    Parcer(string &&expression);
    bool parce();

};


