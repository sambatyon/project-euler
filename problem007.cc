#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  unsigned n = 3;
  std::vector<unsigned long long> primes;
  primes.push_back(2);
  primes.push_back(n);
  while (primes.size() < 10001) {
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
  std::cout << *primes.rbegin() << '\n';
  return 0;
}
