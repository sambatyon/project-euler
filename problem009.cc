#include <iostream>
#include <cstdint>
#include <vector>
#include <cstdio>

using namespace std;

std::uint64_t gcd(std::uint64_t a, std::uint64_t b) {
  while (b) {
    std::uint64_t tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

int main(int argc, char **argv) {
  int m = 2;
  int n;
  uint64_t primitive[3] = {0};

  while (primitive[0] + primitive[1] + primitive[2] < 2000) {
    // use euclids algorithm to generate primitive triplets
    // http://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
    n = 1;
    while (n < m) {
      if (gcd(n, m) != 1 || (m - n) % 2 == 0) {
        ++n;
        continue;
      }
      primitive[0] = m * m - n * n;
      primitive[1] = 2 * m * n;
      primitive[2] = m * m + n * n;
      uint64_t k = 1;
      uint64_t test[3] = {0};
      do {
        test[0] = k * primitive[0];
        test[1] = k * primitive[1];
        test[2] = k * primitive[2];
        ++k;
        if (test[0] + test[1] + test[2] == 1000) {
          cout << test[0] * test[1] * test[2] << '\n';
          return 0;
        }
      } while (test[0] + test[1] + test[2] < 1000);
      ++n;
    }
    ++m;
  }

  return 0;
}
