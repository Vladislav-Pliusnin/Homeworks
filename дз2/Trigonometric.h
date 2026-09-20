#pragma once
#include "ComplexNumber.h"

class Trigonometric : public ComplexNumber {
    private:
    double r;
    double alpha;

    public:
    Trigonometric (double module, double corner);

    void print() const override;

    void fromTrigtoAlg(double a, double b);

    Trigonometric operator*(const Trigonometric& other) const;
    Trigonometric operator/(const Trigonometric& other) const;
    Trigonometric operator+(const Trigonometric& other) const;
    Trigonometric operator-(const Trigonometric& other) const;
};