#include <iostream>

// using namespace std; - после этой команды можно будет не писать std:: все время

int increment(int x) {
    return x + 1;
}

double increment(double x) {
    return x + 1;
}

char increment(char x) {
    return x + 1;
}

int main() {
    int x;
    
    std::cout << 65 << std::endl;

    
    return 0;
}
