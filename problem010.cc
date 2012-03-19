#include <iostream>
#include <cstdint>
#include <vector>

int main(int argc, char **argv) {
  unsigned n = 3;
  std::uint64_t acc = 2 + 3;
  std::vector<std::uint64_t> primes;
  primes.push_back(2);
  primes.push_back(n);
  while (2000000 > *primes.rbegin()) {
    n += 2;
    for (unsigned k = 1; k < primes.size(); ++k) {
      if (n % primes[k] == 0)
        break;
      if (n / primes[k] <= primes[k]) {
        primes.push_back(n);
        acc += n;
        break;
      }
    }
  }
  acc -= *primes.rbegin();
  std::cout << acc << '\n';

  return 0;
}
