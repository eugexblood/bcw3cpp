#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector {
    private:
        double x;
        double y;
    public:
        Vector(double x=0, double y=0);
        ~Vector();

        double getX() const;
        double getY() const;

        void setX(double value);
        void setY(double value);

        double len() const;
        bool operator==(const Vector& other) const;
        bool operator!=(const Vector& other) const;
        void operator+=(const Vector& other);
        void operator-=(const Vector& other);
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
};

std::ostream& operator<<(std::ostream& out, const Vector& vector);

#endif //VECTOR_H