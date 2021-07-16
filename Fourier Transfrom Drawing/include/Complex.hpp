#pragma once
#include <iostream>
#include <cmath>

class Complex {
private:
    double real, imaginary;
    friend std::ostream & operator<<(std::ostream &, const Complex &);

public:
    Complex(double real, double imaginary);
    ~Complex();
    // getter
    double getReal() const;
    double getImaginary() const;

    Complex operator + (Complex &other);
    Complex operator - (Complex &other);
    Complex operator * (Complex &other);
    Complex operator / (Complex &other);
    Complex Conjugate(Complex &c);
    double amplitude();
};