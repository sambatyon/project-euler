#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

std::set<std::uint32_t> GeneratePrimes(std::uint32_t highest);
bool IsTruncatablePrime(std::uint32_t p, const std::set<std::uint32_t> &primes);

int main(int argc, char **argv) {
    auto primes = GeneratePrimes(1000000);
    auto p = primes.find(11);
    std::uint32_t solution = 0;
    std::for_each(p, std::end(primes), [&](std::uint32_t p) {
        if (IsTruncatablePrime(p, primes))
            solution += p;
    });
    std::cout << solution << '\n';
    return 0;
}

bool IsTruncatablePrime(std::uint32_t p, const std::set<std::uint32_t> &primes) {
    if (primes.find(p) == primes.end())
        return false;
    std::uint32_t power = static_cast<unsigned>(std::ceil(std::pow(10, static_cast<unsigned>(std::log10(p)))));
    while (power >= 10) {
        if (primes.find(p / power) == primes.end())
            return false;
        if (primes.find(p % power) == primes.end())
            return false;
        power /= 10;
    }
    return true;
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
