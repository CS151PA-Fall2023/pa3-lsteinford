/**
 * @file Rational.h
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-09-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <numeric>
#include <sstream>

class Rational{
public:
    Rational();
    Rational(int num, int den);
    Rational(const char *fraction);
    Rational(const Rational &copy);

    friend std::ostream &operator<<(std::ostream &os, const Rational &rational);

    operator double() const;

    void reduce();

    Rational operator=(const char *str);
    Rational operator+(const Rational &other);
    Rational operator-(const Rational &other);
    Rational operator/(const Rational &other);
    Rational operator*(const Rational &other);

private:
    int numerator, denominator;

};


#endif