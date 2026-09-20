#include "Trigonometric.h"
#include <iostream>
#include <cmath>

Trigonometric::Trigonometric(double module, double corner) : r(module), alpha(corner) {}

void Trigonometric::fromTrigtoAlg(double a, double b) {
    r = sqrt(a * a + b * b);
    alpha = atan2(b, a);
}

void Trigonometric::print() const {
    std::cout << r << " * (cos(" << alpha << ") + i * sin(" << alpha << "))";
}

Trigonometric Trigonometric::operator*(const Trigonometric& other) const {
        return Trigonometric(r * other.r, alpha + other.alpha);
    }

    Trigonometric Trigonometric::operator/(const Trigonometric& other) const {
        return Trigonometric(r / other.r, alpha - other.alpha);
    }

    Trigonometric Trigonometric::operator+(const Trigonometric& other) const {
        double a1 = r * cos(alpha);
        double b1 = r * sin(alpha);

        double a2 = other.r * cos(other.alpha);
        double b2 = other.r * sin(other.alpha);

        double new_a = a1 + a2;
        double new_b = b1 + b2;

        Trigonometric result(0, 0);
        result.fromTrigtoAlg(new_a, new_b);
        return result;
    }

    Trigonometric Trigonometric::operator-(const Trigonometric& other) const {
        double a1 = r * cos(alpha);
        double b1 = r * sin(alpha);

        double a2 = other.r * cos(other.alpha);
        double b2 = other.r * sin(other.alpha);

        double new_a = a1 - a2;
        double new_b = b1 - b2;

        Trigonometric result(0, 0);
        result.fromTrigtoAlg(new_a, new_b);
        return result;
    }