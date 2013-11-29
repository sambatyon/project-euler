#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdint>
#include <vector>
#include <cmath>
#include <set>
// I use string conversion to deal with the case when the number includes 0, but if a number
// includes 0's is not going to be a magic_prime, so I could have save me that.
// on the other hand, to get the number of digits use log10(number + 0.5)


std::set<std::uint32_t> GeneratePrimes(std::uint32_t highest);
std::uint32_t NextRotation(std::uint32_t);
int FindHighestPower(std::uint32_t number);

int main(int argc, char **argv) {
    auto primes = GeneratePrimes(1000000);
    std::set<std::uint32_t> magic_primes;
    for (const auto &p : primes) {
        auto test = p;
        auto is_magic_prime = true;
        std::vector<std::uint32_t> the_primes;
        do {
            test = NextRotation(test);
            if (primes.find(test) == primes.end()) {
                is_magic_prime = false;
                break;
            } else {
                the_primes.push_back(test);
            }
        } while (test != p);
        if (is_magic_prime && !the_primes.empty())
            std::copy(std::begin(the_primes), std::end(the_primes), std::inserter(magic_primes, std::end(magic_primes)));
    }
    std::cout << magic_primes.size() << '\n';
    return 0;
}

std::uint32_t NextRotation(std::uint32_t num) {
    auto high = FindHighestPower(num);
    auto digit = num % 10;
    return (num / 10) + (digit * high);
}

int FindHighestPower(std::uint32_t number) {
    return number ? static_cast<unsigned>(std::ceil(std::pow(10, static_cast<unsigned>(std::log10(number))))) : -1;
}

std::set<std::uint32_t> GeneratePrimes(std::uint32_t highest) {
    unsigned n = 3;
    std::set<std::uint32_t> primes;
    primes.insert(2);
    primes.insert(n);
    while (n <= highest) {
        n += 2;
        for (const auto &p : primes) {
            if (n % p == 0)
                break;
            if (n / p <= p) {
                primes.insert(n);
                break;
            }
        }
    }
    return primes;
}
