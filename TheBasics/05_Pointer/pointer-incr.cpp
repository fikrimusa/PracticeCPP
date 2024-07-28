#include <format>
#include <iostream>
#include <cstdint>

using std::format;
using std::cout;

using int_type = uint8_t;

void printp(const int_type* p) {
    cout << format("pointer is {}, value is {}\n", static_cast<const void*>(p), *p);
}

int main() {
    int_type arr[] { 1, 2, 3, 4, 5 };
    int_type* p = arr;
    printp(p++);
    printp(p++);
    printp(p++);
}
