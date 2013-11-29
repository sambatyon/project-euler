#include <iostream>
#include <cstdint>
#include <vector>

int main(int argc, char **argv) {
  unsigned n = 3;
  std::uint64_t acc = 2 + 3;
  std::vector<std::uint64_t> primes;
  primes.push_back(2);
  primes.push_back(n);
  while (2000000 > primes.back()) {
    n += 2;
    for (auto p : primes) {
      if (n % p == 0)
        break;
      if (n / p <= p) {
        primes.push_back(n);
        acc += n;
        break;
      }
    }
  }
  acc -= primes.back();
  std::cout << acc << '\n';

  return 0;
}
