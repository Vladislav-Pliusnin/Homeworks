#include "Algebraic.h"
#include <iostream>

Algebraic::Algebraic(double real, double imag) : a(real), b(imag) {}

void Algebraic::print() const {
    std::cout << a;
    if (b >= 0) {
        std::cout << " + " << b << " * i";
    }
    else {
        std::cout << " - " << -b << " * i";
    }
}

Algebraic Algebraic::operator+(const Algebraic& other) const {
    return Algebraic(a + other.a, b + other.b);
}

Algebraic Algebraic::operator-(const Algebraic& other) const {
    return Algebraic(a - other.a, b - other.b);
}

Algebraic Algebraic::operator*(const Algebraic& other) const {
    double new_a = a * other.a - b * other.b;
    double new_b = a * other.b + b * other.a;
    return Algebraic(new_a, new_b);
}

Algebraic Algebraic::operator/(const Algebraic& other) const {
    double denominator = other.a * other.a + other.b * other.b;
    double new_a = (a * other.a + b * other.b) / denominator;
    double new_b = (b * other.a - a * other.b) / denominator;
    return Algebraic(new_a, new_b);
}