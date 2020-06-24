#include "Unit.h"
   
Unit::Unit(const std::string& name, int hp, int dmg) {
    this->name = name;
    if ( hp < 1 ) {
        this->hitPointsLimit = 10; // user will not be able to create "dead" unit and hp will has default value == 10.
    } else {
        this->hitPointsLimit = hp;
    }
    this-> hitPoints = hitPointsLimit; // this sets hp on maximum level for this unit.
    if ( dmg < 0 ) {
        this->damage = 3; // this will set damage to default
    } else {
        this->damage = dmg; // in case dmg==0 unit can't damage enemy;
    }
}

Unit::~Unit() {}

int Unit::getDamage() const {
    return this->damage;
}

int Unit::getHitPoints() const {
    return this->hitPoints;
}

int Unit::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

const std::string& Unit::getName() const {
    return this->name;
}

void Unit::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

void Unit::addHitPoints(int hp) {
    this->ensureIsAlive();
    this->hitPoints += hp;
    if ( this->hitPoints >= this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        std::cout << this->name << " is fully healed." << std::endl;
    } else {
        std::cout << this->name << " is healed." << std::endl;
    }
}

void Unit::takeDamage(int dmg) {
    this->ensureIsAlive();
    this->hitPoints -= dmg;
    if ( this->hitPoints <= 0 ) {
        this->hitPoints = 0;
        std::cout << this->name << " is dead." << std::endl;
    } else {
        std::cout << this->name << " is taking damage." << std::endl;
    }
}

void Unit::attack(Unit& enemy) {
    this->ensureIsAlive();
    std::cout << this->name << " attacks " << enemy.getName() << "." << std::endl;
    enemy.takeDamage(this->damage);
    if ( enemy.getHitPoints() > 0 ) {
        this->counterAttack(enemy);
    }
}

void Unit::counterAttack(Unit& enemy) {
    std::cout << enemy.getName() << " counter attacks " << this->name << "." << std::endl;
    this->takeDamage(enemy.getDamage()/2);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit " << unit.getName() << " has " << unit.getHitPoints() << "/";
    out << unit.getHitPointsLimit() << " hp and " << unit.getDamage() << " damage value.";
    return out;
}
