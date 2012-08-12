#include <iostream>
#include <utility>
#include <cstdint>

std::pair<std::uint16_t, std::uint16_t> reduce(std::uint16_t num,
                                               std::uint16_t den);

bool test_fraction(std::uint16_t i, std::uint16_t j, std::uint16_t ik,
                   std::uint16_t jk);

int main(int argc, char **argv) {
  std::uint16_t gnum = 1;
  std::uint16_t gden = 1;
  for (std::uint16_t i = 1; i < 10; ++i) {
    for (std::uint16_t j = i; j < 10; ++j) {
      for (std::uint16_t k = 1; k < 10; ++k) {
        std::uint16_t num = 10 * i + k;
        std::uint16_t den = 10 * j + k;
        if (den > num && test_fraction(i, j, num, den)) {
          gnum *= i;
          gden *= j;
        }
        num = 10 * k + i;
        den = 10 * j + k;
        if (den > num && test_fraction(i, j, num, den)) {
          gnum *= i;
          gden *= j;
        }
        num = 10 * i + k;
        den = 10 * k + j;
        if (den > num && test_fraction(i, j, num, den)) {
          gnum *= i;
          gden *= j;
        }
        num = 10 * k + i;
        den = 10 * k + j;
        if (den > num && test_fraction(i, j, num, den)) {
          gnum *= i;
          gden *= j;
        }
      }
    }
  }
  auto reduced = reduce(gnum, gden);
  std::cout << reduced.second << '\n';
  return 0;
}

std::uint16_t gcd(std::uint16_t a, std::uint16_t b) {
  while (b) {
    std::uint16_t tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

std::pair<std::uint16_t, std::uint16_t> reduce(std::uint16_t num,
                                               std::uint16_t den) {
  std::uint16_t frac_gcd = gcd(num, den);
  return std::make_pair(num / frac_gcd, den / frac_gcd);
}

bool test_fraction(std::uint16_t i, std::uint16_t j, std::uint16_t ik,
                   std::uint16_t jk) {
  std::pair<std::uint16_t, std::uint16_t> red_orig = reduce(i, j);
  std::pair<std::uint16_t, std::uint16_t> red = reduce(ik, jk);
  return red.first == red_orig.first && red.second == red_orig.second;
}
