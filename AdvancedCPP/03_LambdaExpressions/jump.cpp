#include <format>
#include <iostream>
#include <string>
#include <map>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

const char prompt(const char * p) {
    auto char_upper = [](char c) ->char {
        if(c >= 'a' && c <= 'z') return c - ('a' - 'A');
        else return c;
    };

    std::string r {};
    print("{} > ", p);
    getline(std::cin, r, '\n');

    if (r.size() < 1) return '\0';
    else if (r.size() > 1) {
        print("Response too long\n");
        return '\0';
    }
    else return char_upper(r.at(0));
}

bool jump(const char select) {
    // alternately, this works too --
    // using jumpfunc = std::function<void()>;
    // std::function requires the <functional> header
    using jumpfunc = void(*)();

    const std::map<char, jumpfunc> jumpmap {
        { 'A', []{ print("func A\n"); } },
        { 'B', []{ print("func B\n"); } },
        { 'C', []{ print("func C\n"); } },
        { 'D', []{ print("func D\n"); } },
    };
    
    const auto it = jumpmap.find(select);
    if (it != jumpmap.end()) it->second();
    else {
        print("Invalid response\n");
        return false;
    }
    return true;
}

int main() {
    const char* pstr {"What to do? (A/B/C/D/X)"};
    for (auto key = prompt(pstr); key != 'X'; key = prompt(pstr)) {
        if (key) jump(key);
    }
    print("Bye!\n");
}
