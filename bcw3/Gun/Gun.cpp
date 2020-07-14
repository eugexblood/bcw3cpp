#include "Gun.h"

Gun::Gun(const std::string& model, int capacity) : model(model), capacity(capacity) {
    this->amount = 0;
    this->isReady = false;
    this->totalShots = 0;
}

Gun::~Gun() {}

int Gun::getAmount() const {
    return this->amount;
}

int Gun::getCapacity() const {
    return this->capacity;
}

bool Gun::ready() const {
    return this->isReady;
}

const std::string& Gun::getModel() const {
    return this->model;
}

int Gun::getTotalShots() const {
    return totalShots;
}

void Gun::prepare() {
    this->isReady = true; // "true" is used instead "!this->isReady" so method prepare() will not set "false"
    std::cout << this->model << ": click-click! Ready to shoot." << std::endl;
}

void Gun::reload() {
    this->amount = this->capacity;
    this->isReady = false; // you will need to prepare before shoot again.
    std::cout << this->model << ": zzzip! Reloaded." << std::endl;
}

void Gun::shoot() {
    if ( this->ready() == false ) {
        throw NotReady();
    }
    if ( this->amount == 0 ) {
        throw OutOfRounds();
    }
    std::cout << this->model << ": 'Bang!'" << std::endl;
    this->amount -= 1;
    this->totalShots += 1;
}

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << gun.getModel() << " has capacity " << gun.getCapacity();
    out << ", total shots made: " << gun.getTotalShots();
    out << ". Loaded rounds: " << gun.getAmount() << ", the gun ";
    if ( gun.ready() ) {
        out << "is ready to shoot." << std::endl;
    } else {
        out << "is not ready to shoot." << std::endl;
    }
    out << "****************";
    return out;
}
