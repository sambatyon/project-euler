#include <iostream>
#include <vector>

#include <cstdint>

std::uint64_t fact(std::uint64_t n);

int main(int argc, char **argv) {
  std::vector<std::uint64_t> facts;
  facts.push_back(1);
  while (facts.size() < 10)
    facts.push_back(fact(facts.size()));
  std::uint64_t curious_sum = 0;
  for (std::uint64_t i = 10ull; i < 99999ull; ++i) {
    auto sum = 0ull;
    auto tmp = i;
    do {
      sum += facts[tmp % 10];
      tmp /= 10;
    } while (tmp);
    if (sum == i)
      curious_sum += i;
  }
  std::cout << curious_sum << '\n';
  return 0;
}

std::uint64_t fact(std::uint64_t n) {
  std::uint64_t res = 1;
  while (n > 0)
    res *= n--;
  return res;
}


