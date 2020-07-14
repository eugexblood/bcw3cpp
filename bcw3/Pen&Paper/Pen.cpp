#include "Pen.h"

Pen::Pen(int inkCapacity) {
    if ( inkCapacity < 1 ) {
        this->inkCapacity = 4096; // In case user sets inkCapacity <=0 program sets this parameter to default.
    } else {
        this->inkCapacity = inkCapacity;
    }
    this->inkAmount = this->inkCapacity;
}

Pen::~Pen() {}

int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    int space, messageSize;
    
    if ( this->inkAmount == 0 ) {
        throw OutOfInk();
    }
    
    space = paper.getMaxSymbols() - paper.getSymbols();
    messageSize = message.size();
    
    if ( this->inkAmount > space && messageSize > space ) {
        this->inkAmount -= space;
        paper.addContent(message);
        return;
    }   
    if ( this->inkAmount <= space && messageSize > this->inkAmount ) {
        paper.addContent(message.substr(0, this->inkAmount));
        this->inkAmount = 0;
        throw OutOfInk();
    }
    
    paper.addContent(message);
    this->inkAmount -= messageSize;
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
    std::cout << "Pen refilled." << std::endl;
    
}
        