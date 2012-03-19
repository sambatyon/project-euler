#include <iostream>
#include <cmath>
#include <vector>

std::vector<unsigned long long> primes(const unsigned long long &max);

int main(int argc, char **argv) {
  const unsigned long long number = 600851475143LLU;
  unsigned long long sq = std::sqrt(number);
  std::vector<unsigned long long> pr = primes(sq);
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
std::vector<unsigned long long> primes(const unsigned long long &max) {
  unsigned n = 3;
  std::vector<unsigned long long> primes;
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
