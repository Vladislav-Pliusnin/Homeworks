#include "Algebraic.h"
#include "Trigonometric.h"
#include <iostream>
#include <cmath>


void Quadratic (double a, double b, double c) {
    
    if (a == 1) {
        std::cout << "x^2 "; 
    }
    if (a == -1) {
        std::cout << "-x^2 ";
    }
    if (a < -1 || a > 1) {
        std::cout << a << "x^2 ";
    }

    if (b == 1) {
        std::cout << "+x "; 
    }
    if (b == -1) {
        std::cout << "-x ";
    }
    if (b > 1) {
        std::cout << "+" << b << "x ";
    }
    if (b < -1) {
        std::cout << "-" << b << "x ";
    }

    if (c > 0) {
        std::cout << "+ " << c; 
    }
    if (c < 0) {
        std::cout << "- " << c;
    }
    std::cout << " = 0\n"; 
    double D = b * b - 4 * a * c;
    if (D >= 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        
        std::cout << "D = " << D << "\n";
        std::cout << "x1 = " << x1 << "\n";
        std::cout << "x2 = " << x2 << "\n";
        std::cout << "\n";
    }
    else {
        
        double realElem = -b / (2 * a);
        double imagElem = sqrt(-D) / (2 * a);
        
        std::cout << "D = " << D << " < 0\n";
        std::cout << "x1 = ";
        Algebraic X1(realElem, imagElem);
        X1.print();
        std::cout << "\n";
        
        std::cout << "x2 = ";
        Algebraic X2(realElem, -imagElem);
        X2.print();
        std::cout << "\n";
    }
}

void demonstrateTrigonometric() {
    std::cout << "\nTrigonometric form\n";
    
    Trigonometric num1(5, 0.5); 
    Trigonometric num2(3, 0.3);  
    
    std::cout << "First number: ";
    num1.print();
    std::cout << "\n";
    
    std::cout << "Second number: ";
    num2.print();
    std::cout << "\n";
    
    std::cout << "Multiplication: ";
    Trigonometric product1 = num1 * num2;
    product1.print();
    std::cout << "\n";
    
    std::cout << "division: ";
    Trigonometric product2 = num1 / num2;
    product2.print();
    std::cout << "\n";
}

void demonstrateAlgebraic() {
    std::cout << "\nAlgebraic form\n";
    
    Algebraic num1(3, 4); 
    Algebraic num2(1, 2); 
    
    std::cout << "First number: ";
    num1.print();
    std::cout << "\n";
    
    std::cout << "Second number: ";
    num2.print();
    std::cout << "\n";
    
    std::cout << "Addition: ";
    Algebraic product1 = num1 + num2;
    product1.print();
    std::cout << "\n";
    
    std::cout << "Subtraction: ";
    Algebraic product2 = num1 - num2;
    product2.print();
    std::cout << "\n";
    
    std::cout << "Multiplication: ";
    Algebraic product3 = num1 * num2;
    product3.print();
    std::cout << "\n";
    
    std::cout << "Division: ";
    Algebraic product4 = num1 / num2;
    product4.print();
    std::cout << "\n";
}
int main() {
    double a, b, c;
    
    std::cout << "Choose a: ";
    std::cin >> a;
    
    std::cout << "Choose b: ";
    std::cin >> b;
    
    std::cout << "Choose c: ";
    std::cin >> c;
    
    Quadratic(a, b, c);
    demonstrateTrigonometric();
    demonstrateAlgebraic();
    return 0;
}