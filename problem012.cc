#include <iostream>
#include <vector>
#include <cstdint>

std::vector<std::uint64_t> gen_primes(const std::uint64_t &max);
std::uint64_t count_divisors(std::uint64_t number);

int main(int argc, char **argv) {
  std::uint64_t current = 3;
  std::uint64_t index = 3;
  while (count_divisors(current) < 500)
    current += index++;
  std::cout << current << '\n';
  return 0;
}

/**
 * Uses the division function as described here:
 * http://en.wikipedia.org/wiki/Divisor_function#Properties
 */
std::uint64_t count_divisors(std::uint64_t number) {
  static std::vector<std::uint64_t> primes = gen_primes(30000);
  int i = 0;
  std::uint64_t res = 1;
  while (number != 1) {
    int exponent = 0;
    while (number % primes[i] == 0) {
      number /= primes[i];
      ++exponent;
    }
    ++i;
    res *= exponent + 1;
  }
  return res;
}

/**
 * Uses the primes generator algorithm from TAOCP vol. 1
 */
std::vector<std::uint64_t> gen_primes(const std::uint64_t &max) {
  unsigned n = 3;
  std::vector<std::uint64_t> primes;
  primes.push_back(2);
  primes.push_back(n);
  while (n <= max) {
    n += 2;
    for (unsigned k = 1; k < primes.size(); ++k) {
      if (n % primes[k] == 0)
        break;
      if (n / primes[k] <= primes[k]) {
        primes.push_back(n);
        break;
      }
    }
  }
  return primes;
}


