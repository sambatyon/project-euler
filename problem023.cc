#include <set>
#include <cmath>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <iostream>

inline
bool is_abundand(const int &number);

int main(int argc, char **argv) {
  std::set<int> abundant_numbers;
  for (int i = 1; i <= 28123; ++i)
    if (is_abundand(i))
    abundant_numbers.insert(i);

  int addition = 0;
  for (int i = 1; i <= 28123; ++i) {
    auto it = abundant_numbers.begin();
    bool sum_of_abundants = false;
    while (*it <= i) {
      if (abundant_numbers.find(i - *(it++)) != abundant_numbers.end()) {
        sum_of_abundants = true;
        break;
      }
    }
    if (!sum_of_abundants)
      addition += i;
  }
  std::printf("%d\n", addition);
  return 0;
}

int divisors(const int &n) {
  const double root = std::sqrt(n);
  const int nroot = static_cast<int>(std::floor(root));
  int res = 0;
  for (int i = 1; i <= nroot; ++i)
    if (n % i == 0)
      res += i + n / i;
  if (nroot * nroot == n)
    res -= nroot;
  return res - n;
}

inline
bool is_abundand(const int &number) {
  return number < divisors(number);
}
