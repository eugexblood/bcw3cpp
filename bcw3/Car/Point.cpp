#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

Point::~Point() {}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

double Point::distance(const Point& other) const {
    return hypot(this->x - other.getX(), this->y - other.getY());
}

bool Point::operator==(const Point& other) const {
    return this->getX() == other.getX() && this->getY() == other.getY();
}

bool Point::operator!=(const Point& other) const {
    return !((*this) == other);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.getX() << ", " << point.getY() << ")";
    return out;
}
