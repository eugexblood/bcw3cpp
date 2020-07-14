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

        void setX(double value);
        void setY(double value);

        double distance(const Point& other) const;
        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;
        
        // reloading of operator = so we don't need copy constructor
        // void operator=(const Point& other);
        
        friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif // POINT_H