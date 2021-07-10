
#include "parcer.hpp"


Parcer::Parcer(string &&expression) : _coefficients(), _expression(expression) {}

Parcer::~Parcer() = default;

char Parcer::_check_for_separator(const char &c, const string &separators)
{
    for (const char &s : separators)
    {
        if (s == c)
            return c;
    }
    return 0;
}

void Parcer::_split(vector<string> &result, const string &input, const string &separators, int side)
{
    int idx = 0;
    size_t i = 0;
    char c;

    _sign_of_coef[0] = side == FIRST_SIDE ? 1 : -1;
    for (; i < input.size(); ++i)
    {
        c = _check_for_separator(input[i], separators);
        if (c) {
            result.push_back(input.substr(idx, i - idx));
            if (c == '-') {
                _sign_of_coef[result.size()] = side == FIRST_SIDE ? -1 : 1;
            }
            else
                _sign_of_coef[result.size()] = side == FIRST_SIDE ? 1 : -1;
            idx = i + 1;
        }
    }
    result.push_back(input.substr(idx, i));
}


bool Parcer::_check_forbidden_symbol(char s)
{
    if (isdigit(s) || s == '*' || s == 'X' || s == '^' || s == '.' || s == ' ')
        return true;
    return false;
}

bool Parcer::_print_error(int error_num)
{
    if (error_num == 0)
        cout << "Syntax error" << endl;
    return false;
}


void Parcer::_trim(string &str)
{
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
}

bool Parcer::_write_into_map(const string &str, int degree, float num, int token_num)
{
    size_t degree_pos = 0;

    if ((degree_pos = str.find('^')) != string::npos) {
        if (degree_pos + 1 < str.size())
            degree = stoi(str.substr(degree_pos + 1));
        else
            return false;
    }
    if (!_coefficients.count(degree))
        _coefficients[degree] = 0;
    _coefficients[degree] += num * _sign_of_coef[token_num];
    return true;
}

bool Parcer::_validate(bool *validation, int &degree, const string &str, int idx)
{
    if (!_check_forbidden_symbol(str[idx]))
        return false;
    if (str[idx] == '*') {
        if (!validation[1] && !validation[0] && !validation[2])
            validation[0] = true;
        else
            return false;
    }
    if (str[idx] == 'X') {
        degree = 1;
        if (!validation[1] && !validation[2])
            validation[1] = true;
        else
            return false;
    }
    if (str[idx] == '^') {
        if (validation[1] && !validation[2])
            validation[2] = true;
        else
            return false;
    }
    return true;
}

bool Parcer::_parce_coefficients(string &str, int token_num)
{
    int degree = 0;
    bool validation[3] = { false, false, false };
    size_t idx = 0;
    // _trim(str);
    float num = stof(str, &idx);

    for (; idx < str.size(); ++idx)
    {
        if (!_validate(validation, degree, str, idx))
            return _print_error(SYNTAX_ERROR);
    }
    if (!_write_into_map(str, degree, num, token_num))
        return _print_error(SYNTAX_ERROR);
    return true;
}

bool Parcer::_parce_sides(vector<string> &side)
{
    for (size_t i = 0; i < side.size(); ++i) {
        _trim(side[i]);
        if (side[i] == "") {
            if (i != 0)
                return false;
        }
        else if (!_parce_coefficients(side[i], i))
            return false;
    }
    return true;
}

void Parcer::__print_coefs()
{
    for (auto &v : _coefficients) {
        cout << v.first << "  " << v.second << endl;
    }
}

bool Parcer::parce() {

    vector<string> sides;
    vector<string> first_side;
    vector<string> second_side;

    _split(sides, _expression, "=", 3);
    if (sides.size() != 2)
        return _print_error(SYNTAX_ERROR);
    _split(first_side, sides[0], "+-", FIRST_SIDE);
    if (!_parce_sides(first_side))
        return false;
    _split(second_side, sides[1], "+-", SECOND_SIDE);
    if (!_parce_sides(second_side))
        return false;
    return true;
}

const map<int, float> &Parcer::get_coefficients() const {
    return _coefficients;
}

