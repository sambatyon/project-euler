#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <string>
#include <vector>

unsigned recurring_cycle_length(unsigned num, const unsigned &den);

int main(int argc, char **argv) {
  unsigned max_lenght = 0;
  unsigned max_value = 0;
  for (int i = 2; i < 1000; ++i) {
    unsigned length = recurring_cycle_length(10, i);
    if (length > max_lenght) {
      max_lenght = length;
      max_value = i;
    }
  }
  std::cout << max_value << '\n';
  return 0;
}

unsigned recurring_cycle_length(unsigned num, const unsigned &den) {
  std::vector<std::pair<unsigned, unsigned> > decimals;
  std::pair<unsigned, unsigned> current = std::make_pair(num / den, num % den);
  while (current.second &&
         std::find(decimals.begin(), decimals.end(), current) == decimals.end())
  {
    decimals.push_back(current);
    num = current.second * 10;
    current = std::make_pair(num / den, num % den);
  }

  if (!current.second)
    return 0;

  return std::distance(std::find(decimals.begin(), decimals.end(), current),
                       decimals.end());
}
