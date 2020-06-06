#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
    private:
        double real;
        double imaginary;
    public:
        Complex(double real=0, double imaginary=0);
        ~Complex();

        double getReal() const;
        double getImaginary() const;

        bool operator==(const Complex& other) const;
        bool operator!=(const Complex& other) const;
        void operator+=(const Complex& other);
        void operator-=(const Complex& other);
        Complex operator+(const Complex& other) const;
        Complex operator-(const Complex& other) const;
        Complex operator*(const Complex& other) const;
};

std::ostream& operator<<(std::ostream& out, const Complex& complex);

#endif //COMPLEX_H