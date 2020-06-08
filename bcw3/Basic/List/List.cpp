#include "List.h"

List::List(int capacity, double multiplier) : capacity(capacity), multiplier(multiplier), current(0) {
    this->array = (int*)malloc(capacity*sizeof(int));
    
    if ( this->array == NULL ) {
        throw OutOfMemoryException();
    }
}

List::~List() {
    free(this->array);
}

int List::size() const {
    return this->current;
}

int List::max_size() const {
    return this->capacity;
}

void List::erase(int index) {
    if ( index >= 0 && index < this->current ) {
        this->current -= 1;
        for ( int i = index, j = index + 1; i < this->current; i++, j++ ) {
            this->array[i] = this->array[j];
        }
    } else {
        std::cout << "No element with index " << index << " in this list." << std::endl;
    }
}

void List::insert(int value, int index) {
    if ( index >= 0 && index < this->current ) {
        this->push_back(this->array[this->current-1]);
        
        for ( int i = this->current - 2, j = i - 1; i > index; i--, j-- ) {
            this->array[i] = this->array[j];
        }
        
        this->array[index] = value;
    } else {
        std::cout << "No element with index " << index << " in this list." << std::endl;
    }
}

int List::find(int value) const {
    for ( int i = 0; i < this->current; i++ ) {
        if ( this->array[i] == value ) {
            return i;
        }
    }
    return -1;
}

void List::push_back(int value) {
    int newCurrent = this->current + 1;
    
    if ( newCurrent > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(this->array, newCapacity*sizeof(int));
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->array = newArray;
        this->capacity = newCapacity;
    }
    this->array[current] = value;
    this->current = newCurrent;
}

int List::pop_back() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    
    this->current -= 1;
    return this->array[this->current];
}

void List::sort() {
    for ( int i = 0; i < this->current; i++ ) {
        int min = this->array[i];
        int indexMin = i;
        
        for ( int j = i + 1; j < this->current; j++ ) {
            if ( this->array[j] < min ) {
                min = this->array[j];
                indexMin = j;
            }
        }
        if ( indexMin != i ) {
            this->array[indexMin] = this->array[i];
            this->array[i] = min;
        }
    }
}

int List::operator[](int index) const {
    return this->array[index];
}

bool List::operator==(const List& other) const {
    if ( this->current != other.size() || this->capacity != other.max_size() ) {
        return false;
    }
    for ( int i = 0; i < this->current; i++ ) {
        if ( this->array[i] != other[i] ) {
            return false;
        }
    }
    return true;
}

bool List::operator!=(const List& other) const {
    return !((*this) == other);
}

std::ostream& operator<<(std::ostream& out, const List& list) {
    int last = list.size() - 1;
    
    if ( last < 0 ) {
        throw ZeroLenException();
    }
    
    for ( int i = 0; i < last; i++ ) {
        out << list[i] << " ";
    }
    out << list[last];
    return out;
}
