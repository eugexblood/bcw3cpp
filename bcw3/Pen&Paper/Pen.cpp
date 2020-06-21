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
    int space = paper.getMaxSymbols() - paper.getSymbols();
    int messageSize = message.size();
    
    if ( this->inkAmount > space && messageSize > space ) {
        paper.addContent(message.substr(0, space));
        this->inkAmount -= space;
        throw OutOfSpace();
    }
        
    if ( this->inkAmount <= space && messageSize > this->inkAmount ) {
        this->inkAmount = 0;
        paper.addContent(message);
        throw OutOfInk();
    }
    
    paper.addContent(message);
    this->inkAmount -= messageSize;
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
    std::cout << "Pen refilled." << std::endl;
    
}
        