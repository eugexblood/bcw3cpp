#ifndef GUN_H
#define GUN_H

#include <iostream>

class OutOfRounds {};
class NotReady {};

class Gun {
    private:
        int amount;
        int capacity;
        bool isReady;
        std::string model;
        int totalShots;
    public:
        Gun(const std::string& model="Beretta", int capacity=8);
        ~Gun();

        int getAmount() const;
        int getCapacity() const;
        bool ready() const;
        const std::string& getModel() const;
        int getTotalShots() const;

        void prepare();
        void reload();
        void shoot();
};

std::ostream& operator<<(std::ostream& out, const Gun& gun);

#endif //GUN_H