#include <iostream>
#include <cmath>

// переделать все в операторы: +, -, ==, !=,

struct Vector {
    private:
        double x;
        double y;
    
    public:
        double getX() {
            return this->x;
        }
        
        double getY() {
            return this->y;
        }
        
        void setX(double x) {
            this->x = x;
        }
        
        void setY(double y) {
            this->y = y;
        }
        
        void vectorIncrement(const Vector& other) {
            this->x += other.x;
            this->y += other.y;
        }
        
        void vectorDecrement(const Vector& other) {
            this->x -= other.x;
            this->y -= other.y;
        }
        
        bool vectorEqual(const Vector& other) {
            return this->x == other.x && this->y == other.y;
        }
        
        double vectorLen() {
            return hypot(this->x, this->y);
        }
};

std::ostream& operator<<(std::ostream& out, Vector& v) {
    out << "(" << v.getX() << ", " << v.getY() << ")";
    return out;
}

Vector vectorSum(Vector a, Vector& b) {
        a.vectorIncrement(b);
        std::cout << a << std::endl;
        return a;
}

int main() {
    Vector a;
    Vector b;
    double x1, y1, x2, y2;
    
    x1 = 5.4;
    y1 = 6.1;
    x2 = -1.4;
    y2 = 0;
    
    a.setX(x1);
    a.setY(y1);
    
    b.setX(x2);
    b.setY(y2);
    
    std::cout << "Vector A is " << a << std::endl;
    std::cout << "Vector B is " << b << std::endl;
    
    a.vectorIncrement(b);
    std::cout << "A + B is new A " << a << std::endl;
    
    a.vectorDecrement(b);
    std::cout << "New A - B is new A " << a << std::endl;
    
    std::cout << "Vectors A and B are " << (a.vectorEqual(b) ? "equal." : "not equal.") << std::endl;
    
    std::cout << "Vector A length is " << a.vectorLen() << std::endl;
    
    vectorSum(a, b);
    
    // std::cout << vectorSum(a, b) << std::endl;
    
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    
    return 0;
}
