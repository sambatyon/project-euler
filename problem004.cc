#include <iostream>
#include <cstdint>
#include <set>

bool check_palindrome(const std::uint32_t &number);

int main(int argc, char **argv) {
  std::uint32_t max = 999U * 999U;
  std::uint32_t max_pl = 0;
  for (std::uint32_t i = 999; i > 101; --i)
    for (std::uint32_t j = 999; j >= i; --j)
      if (check_palindrome(i * j) && i * j > max_pl)
        max_pl = i * j;
  std::cout << max_pl << '\n';
  return 0;
}

bool check_palindrome(const std::uint32_t &number) {
  std::uint32_t x = number;
  std::uint32_t pal = 0;
  while (x) {
    pal = 10 * pal + (x % 10);
    x /= 10;
  }
  return number == pal;
}
