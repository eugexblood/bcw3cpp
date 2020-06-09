#include "Car.h"
        
Car::Car(double capacity, double consumption, const Point& location, const std::string& model) {
    this->fuelAmount = 0;
    this->fuelCapacity = capacity;
    this->fuelConsumption = consumption;
    this->location = location;
    this->model = model;
}

Car::~Car() {}

double Car::getFuelAmount() const {
    return this->fuelAmount;
}

double Car::getFuelCapacity() const {
    return this->fuelCapacity;
}

double Car::getFuelConsumption() const {
    return this->fuelConsumption;
}

const Point& Car::getLocation() const {
    return this->location;
}

const std::string& Car::getModel() const {
    return this->model;
}

void Car::drive(const Point& destination) {
    double distance = destination.distance(this->location);
    double fuelNeeded = distance * this->fuelConsumption;
    
    if ( fuelNeeded > this->fuelAmount ) {
        throw OutOfFuel();
    }
    
    this->location = destination;
    this->fuelAmount -= fuelNeeded;
    std::cout << this->model << " has driven " << distance << "km to " << destination << "." << std::endl;
}

void Car::drive(double x, double y) {
    Point destination = Point(x, y);
    this->drive(destination);
}

void Car::refill(double fuel) {
    double fuelShortage = this->fuelCapacity - this->fuelAmount;
    
    if ( fuel > fuelShortage ) {
        this->fuelAmount = this->fuelCapacity;
        throw TooMuchFuel();
    }
    this->fuelAmount += fuel;
    std::cout << fuel << "l successfully refilled." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << car.getModel() << " is here " << car.getLocation() << ". Fuel amount left: " << car.getFuelAmount() << ".";
    return out;
}
