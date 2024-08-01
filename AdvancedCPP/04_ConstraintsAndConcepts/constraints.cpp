#include <format>
#include <concepts>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

template<typename T>
concept Numeric = requires(T a){
    a + 1; a * 1;
};

auto arg42(const Numeric auto& arg) {
    return arg + 42;
}

int main() {
    auto n = 7.9;
    print("The answer is [{}]\n", arg42(n));
}