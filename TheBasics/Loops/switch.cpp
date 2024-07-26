#include <iostream>

using std::cout;

int main() {
    const auto ONE   = 1;
    const auto TWO   = 2;
    const auto THREE = 3;
    const auto FOUR  = 4;
    
    int x {3};
    
    switch (x) {
        case ONE:
            cout << "one\n";
            break;
        case TWO:
            cout << "two\n";
            break;
        case THREE:
            cout << "three\n";
            break;
        case FOUR:
            cout << "four\n";
            break;
        default:
            cout << "default\n";
            break;
    }
}
