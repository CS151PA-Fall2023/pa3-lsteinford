/**
 * @file Rational.cpp
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-09-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Rational.h"

/**
 * @brief Construct a new Rational: Default Constructore
 * 
 */
Rational::Rational(){
    numerator = 1;
    denominator = 1;
}

/**
 * @brief Construct a new Rational: Int parameters
 * 
 * @param num 
 * @param den 
 */
Rational::Rational(int num, int den){
    numerator = num;
    denominator = den;
}

/**
 * @brief Construct a new Rational: String parameters
 * 
 * @param fraction 
 */
Rational::Rational(const char *fraction){
    std::stringstream string(fraction);
    char delim;
    string >> numerator >> delim >> denominator;
}

/**
 * @brief Construct a new Rational: Copy Constructor
 * 
 * @param copy 
 */
Rational::Rational(const Rational &copy){
    this->numerator = copy.numerator;
    this->denominator = copy.denominator;
}

/**
 * @brief Type conversion to double
 * 
 * @return double 
 */
Rational::operator double() const{
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}

/**
 * @brief Find GCD(greatest common denominator) and reduce by it
 *        Flips negative to numerator if needed
 * 
 */
void Rational::reduce(){
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0){
        numerator *= -1;
        denominator *= -1;
    }
}

/**
 * @brief Assignment operator overload
 * 
 * @param str 
 * @return Rational 
 */
Rational Rational::operator=(const char *str){
    *this = Rational(str);
    return *this;
}

/**
 * @brief Addition operator overload
 * 
 * @param other 
 * @return Rational 
 */
Rational Rational::operator+(const Rational &other){
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief Subtraction operator overload
 * 
 * @param other 
 * @return Rational 
 */
Rational Rational::operator-(const Rational &other){
    int newNum = numerator * other.denominator - other.numerator * denominator;
    int newDen = denominator * other.denominator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief Multiplication operator overload
 * 
 * @param other 
 * @return Rational 
 */
Rational Rational::operator*(const Rational &other){
    int newNum = numerator * other.numerator;
    int newDen = denominator * other.denominator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief Division operator overload
 * 
 * @param other 
 * @return Rational 
 */
Rational Rational::operator/(const Rational &other){
    int newNum = numerator * other.denominator;
    int newDen = denominator * other.numerator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief Stream insertion operator
 * 
 * @param os 
 * @param rational 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Rational &rational){
    os << rational.numerator << '/' << rational.denominator;
    return os;
}