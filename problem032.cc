/**
 * This solution is not very efficient, tries a lot of obviously not
 * solutions, also, using a sstream might not be the fastest way to
 * transform a string to a number, but it works, and I don't have a
 * lot of time.
 *
 * It is just a shame because this is the least eficient of all my
 * algorithms.
 */
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <sstream>
#include <string>
#include <set>

int main(int argc, char **argv) {
  std::string numbers = "123456789";
  std::set<int> products;
  while (std::next_permutation(numbers.begin(), numbers.end())) {
    for (int i = 1; i < 8; ++i) { // inserts the * symbol
      for (int j = i + 1; j < 9; ++j) { // inserts the = symbol
        std::stringstream ss;
        ss << numbers.substr(0, i) << ' '
           << numbers.substr(i, j - i) << ' '
           << numbers.substr(j);
        int a, b, c;
        ss >> a >> b >> c;
        if (a * b == c)
          products.insert(c);
      }
    }
  }
  int sum = 0;
  for (int i : products)
    sum += i;
  std::cout << sum << '\n';
  return 0;
}
