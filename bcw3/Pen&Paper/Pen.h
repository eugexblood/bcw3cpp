#ifndef PEN_H
#define PEN_H

#include <iostream>
#include "Paper.h"

class OutOfInk {};

class Pen {
    private:
        int inkAmount;
        int inkCapacity;
    public:
        Pen(int inkCapacity=4096);
        ~Pen();

        int getInkAmount() const;
        int getInkCapacity() const;

        void write(Paper& paper, const std::string& message);
        void refill();
};


#endif //PEN_H