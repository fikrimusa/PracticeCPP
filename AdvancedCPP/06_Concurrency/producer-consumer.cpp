#include <format>
#include <deque>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <iostream>

// Enable chrono literals
using namespace std::chrono_literals;

constexpr size_t num_items{10};
constexpr auto delay_time{250ms};

std::mutex mtx;
std::deque<size_t> q;
std::atomic_flag finished;

// format-style print (C++20)
void print(std::string_view str_fmt, auto&&... args) {
    std::cout << std::vformat(str_fmt, std::make_format_args(args...));
}

void producer() {
    for (size_t i{}; i < num_items; ++i) {
        std::this_thread::sleep_for(delay_time);
        {
            std::lock_guard lck{mtx};
            q.push_back(i);
            print("push {} on the queue\n", i);
        }
    }

    std::lock_guard lck{mtx};
    finished.test_and_set();
}

void consumer() {
    while (true) {
        {
            std::lock_guard lck{mtx};
            if (!q.empty()) {
                print("pop {} from the queue\n", q.front());
                q.pop_front();
            }
            if (finished.test()) break;
        }
        std::this_thread::sleep_for(10ms);
    }
}

int main() {
    std::thread t1{producer};
    std::thread t2{consumer};
    t1.join();
    t2.join();
    print("finished!\n");
}