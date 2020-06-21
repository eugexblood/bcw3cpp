#include "Paper.h"

Paper::Paper(int maxSymbols) {
    if ( maxSymbols < 1 ) {
        this->maxSymbols = 4096; // In case user sets maxSymbols <=0 program sets this parameter to default.
    } else {
        this->maxSymbols = maxSymbols;
    }
    this->symbols = 0;
}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const std::string& message) {
    int currentSymbols = this->symbols + message.size();
    
    if ( this->symbols == this->maxSymbols ) {
        throw OutOfSpace();
    }
    
    if ( currentSymbols > this->maxSymbols ) {
        this->content += "\n" + message.substr(0, this->maxSymbols - this->symbols);
        this->symbols = this->maxSymbols;
        throw OutOfSpace();
    }
    
    this->symbols = currentSymbols;
    this->content += "\n" + message;
}

void Paper::show() const {
    if ( this->symbols == 0 ) {
        std::cout << "This paper is clean." << std::endl;
    } else {
        std::cout << "Message on this paper: " << this->content << std::endl;
    }
}
