#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    int array[] { 1, 2, 3, 4, 5 };

    for (int i {0}; i < 5; ++i) {
        cout << format("element {} is {}\n", i, array[i]);
    }
}
