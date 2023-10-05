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
    Rational(); //default constructor;
    Rational(int num, int den); //int constructor
    Rational(const char *fraction); //string constructor
    Rational(const Rational &copy); //copy constructor

    operator double() const;
    void reduce();

    Rational operator=(const char *str);
    Rational operator+(const Rational &other);
    Rational operator-(const Rational &other);
    Rational operator/(const Rational &other);
    Rational operator*(const Rational &other);
    
    friend std::ostream &operator<<(std::ostream &os, const Rational &rational);

private:
    int numerator, denominator;

};


#endif