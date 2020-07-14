#include "Vector.h"

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::~Vector() {}

double Vector::getX() const {
    return this->x;
}

double Vector::getY() const {
    return this->y;
}

void Vector::setX(double value) {
    this->x = value;
}

void Vector::setY(double value) {
    this->y = value;
}

double Vector::len() const {
    return hypot(this->x, this->y);
}

bool Vector::operator==(const Vector& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Vector::operator!=(const Vector& other) const {
    return !((*this) == other);
}

void Vector::operator+=(const Vector& other) {
    this->x += other.x;
    this->y += other.y;
}

void Vector::operator-=(const Vector& other) {
    this->x -= other.x;
    this->y -= other.y;
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(this->x + other.x, this->y + other.y);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(this->x - other.x, this->y - other.y);
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
    out << "(" << vector.getX() << ", " << vector.getY() << ")";
    return out;
}
