#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    int array[] { 1, 2, 3, 4, 5 };
    int i {0};

    while (i < 5) {
        cout << format("element {} is {}\n", i, array[i]);
        ++i;
    }
}
