#ifndef PAPER_H
#define PAPER_H

#include <iostream>

class OutOfSpace {};

class Paper {
    private:
        int maxSymbols;
        int symbols;
        std::string content;
    public:
        Paper(int maxSymbols=4096);
        ~Paper();

        int getMaxSymbols() const;
        int getSymbols() const;

        void addContent(const std::string& message);
        void show() const;
};

#endif //PAPER_H