#include <iostream>
#include <cstdint>
#include <vector>
#include <cstdio>

std::uint64_t lcm(std::uint64_t a, std::uint64_t b);
std::uint64_t gcd(std::uint64_t a, std::uint64_t b);

int main(int argc, char **argv) {
  std::uint64_t acc = 2;
  for (std::uint64_t i = 3; i <= 20; ++i)
    acc = lcm(acc, i);
  std::cout << acc << '\n';
  return 0;
}

std::uint64_t lcm(std::uint64_t a, std::uint64_t b) {
  return (a * b) / gcd(a, b);
}

std::uint64_t gcd(std::uint64_t a, std::uint64_t b) {
  while (b) {
    std::uint64_t tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
