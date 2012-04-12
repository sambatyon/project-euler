#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>

std::vector<unsigned> gen_primes(const unsigned &max);

int main(int argc, char **argv) {
  std::vector<unsigned> vprimes = gen_primes(1000u);
  std::set<unsigned> primes(vprimes.begin(), vprimes.end());

  auto b = std::find(vprimes.begin(), vprimes.end(), 41u);

  int saved_a = 1;
  int saved_b = 41;
  int max = 40;

  for (++b; b != vprimes.end(); ++b) {
    int sq = std::sqrt(1 - 4 * (41 - *b));
    int n[2] = {(-1 + sq) / 2, (-1 - sq) / 2};
    int as[2] = {-(2*n[0] + 1), -(2*n[1] + 1)};
    for (int a : as) {
      int count = 0;
      int x = 0;
      unsigned px = 0;
      do {
        ++count;// start with this, since p(0) is prime
        ++x;
        px = x * x + a * x + *b;
      } while (primes.find(px) != primes.end());
      if (count > max) {
        saved_a = a;
        saved_b = *b;
        max = count;
      }
    }
  }
  std::cout << saved_a * saved_b << '\n';

  return 0;
}

/**
 * Uses the primes generator algorithm from TAOCP vol. 1
 */
std::vector<unsigned> gen_primes(const unsigned &max) {
  unsigned n = 3u;
  std::vector<unsigned> primes;
  primes.push_back(2u);
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

