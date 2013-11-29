#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

std::vector<unsigned long long> primes(const unsigned long long &max);

int main(int argc, char **argv) {
  const auto number = 600851475143LLU;
  auto sq = static_cast<std::uint64_t>(std::sqrt(number));
  std::vector<std::uint64_t> pr = primes(sq);
  for (auto it = pr.rbegin(); it != pr.rend(); ++it) {
    if (number % *it == 0) {
      std::cout << *it << '\n';
      break;
    }
  }
  return 0;
}

/**
 * Uses the primes generator algorithm from TAOCP vol. 1
 */
std::vector<std::uint64_t> primes(const std::uint64_t &max) {
  unsigned n = 3;
  std::vector<std::uint64_t> primes;
  primes.push_back(2);
  primes.push_back(n);
  while (n <= max) {
    n += 2;
    for (const auto &p : primes) {
      if (n % p == 0)
        break;
      if (n / p <= p) {
        primes.push_back(n);
        break;
      }
    }
  }
  return primes;
}
