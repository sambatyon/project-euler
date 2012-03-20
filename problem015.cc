#include <iostream>
#include <cstdint>

std::uint64_t n_choose_k(std::uint64_t n, std::uint64_t k);

/// We use the fact that the number of routes on a grid of
/// lenght N is equal to the addition of the squares of the
/// N row of the Pascal's triangle; together with the fact
/// that the addition of the squares of the N row of the
/// Pacal's triangle is (2n choose n)
int main(int argc, char **argv) {
  std::uint64_t n = 20;
  std::cout << n_choose_k(2 * n, n) << '\n';
  return 0;
}

/// Uses the fact that comb(n + 1, k + 1) = (n + 1)/(k + 1) * comb(n, k)
std::uint64_t n_choose_k(std::uint64_t n, std::uint64_t k) {
  if (k > n)
    return 0;

  std::uint64_t r = 1;
  for (std::uint64_t d = 1; d <= k; d++) {
    r *= n--;
    r /= d;
  }
  return r;
}
