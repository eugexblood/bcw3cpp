#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>

class OutOfMemoryException {};
class ZeroLenException {};

class List {
    private:
        int* array;
        int capacity;
        double multiplier;
        int current;
    public:
        List(int capacity=100, double multiplier=1.05);
        ~List();

        int size() const;
        int max_size() const;

        void erase(int index);
        void insert(int value, int index);
        int find(int value) const;
        void push_back(int value);
        int pop_back();
        void sort();

        int operator[](int index) const;
        bool operator==(const List& other) const;
        bool operator!=(const List& other) const;
};

std::ostream& operator<<(std::ostream& out, const List& list);

#endif //LIST_H