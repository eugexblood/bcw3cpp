#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
    private:
        double x;
        double y;
    public:
        Point(double x=0, double y=0);
        ~Point();

        double getX() const;
        double getY() const;
        double distance(const Point& other) const;
        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;
};

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif // POINT_H