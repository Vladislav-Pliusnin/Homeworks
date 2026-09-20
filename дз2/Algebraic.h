#pragma once
#include "ComplexNumber.h"

class Algebraic : public ComplexNumber {
    
    private:
    double a;
    double b;
    
    public:
    Algebraic (double real, double imag);

    void print() const override;

    Algebraic operator+(const Algebraic& other) const;
    Algebraic operator-(const Algebraic& other) const;
    Algebraic operator*(const Algebraic& other) const;
    Algebraic operator/(const Algebraic& other) const;
};