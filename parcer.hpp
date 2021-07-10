


#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#define SYNTAX_ERROR 0
#define FIRST_SIDE 1
#define SECOND_SIDE -1

using namespace std;

enum {
    ZERO_DEGREE,
    FIRST_DEGREE,
    SECOND_DEGREE
};

class Parcer {

private:
    map<float, float> _coefficients;
    string _expression;
    unordered_map<int, int> _sign_of_coef;
    bool _check_forbidden_symbol(char s);
    void _split(vector<string> &result, const string &input, const string &separators, int side);
    char _check_for_separator(const char &c, const string &separators);
    bool  _parce_coefficients(string &str, int token_num);
    bool  _write_into_map(const string &str, float degree, float num, int token_num);
    bool _validate(bool *validation, float &degree, const string &str, int idx);
    void _trim(string &str);
    bool _print_error(int error_num);
    bool _parce_sides(vector<string> &side);


public:

    ~Parcer();
    const map<float, float> &get_coefficients() const;
    Parcer(string &&expression);
    bool parce();
    void __print_coefs();

};


