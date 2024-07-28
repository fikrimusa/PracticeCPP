#include <format>
#include <iostream>

using std::format;
using std::cout;

int main() {
    int array[] { 1, 2, 3, 4, 5 };

    for (const auto& e : array) {
        cout << format("element is {}\n", e);
    }
}
