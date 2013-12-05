#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdint>
#include <string>
#include <deque>

bool IsPandigital(unsigned num);

int main(int argc, char **argv) {
    unsigned max = 0;
    for (unsigned i = 9123; i <= 9876; ++i) {
        unsigned tmp = i * 100000 + 2 * i;
        if (IsPandigital(tmp) && tmp > max)
            max = tmp;
    }
    std::cout << max << '\n';
    return 0;
}

bool IsPandigital(unsigned num) {
    std::deque<int> count(10, 0);
    while (num) {
        ++count[num % 10];
        num /= 10;
    }
    if (count[0])
        return false;
    count.pop_front();
    for (auto c : count)
        if (!c || c > 1)
            return false;
    return true;
}
