#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>

unsigned count(const int &current_coin, const int &value);

int main(int argc, char **argv) {
  unsigned val = count(0, 200);
  std::cout << val << '\n';

  return 0;
}


unsigned count(const int &current_coin, const int &value) {
  static const std::vector<int> coins = {200, 100, 50, 20, 10, 5, 2, 1};
  if (current_coin < 0 || current_coin >= coins.size()) {
    std::stringstream ss;
    ss << current_coin << " is an invalid coin value";
    throw std::range_error(ss.str()); // error
  }
  if (value - coins[current_coin] < 0)
    if (coins[current_coin] == 1)
      return 0;
    else
      return count(current_coin + 1, value);
  if (coins[current_coin] == 1)
    return 1;
  if (value - coins[current_coin] == 0)
    return 1 + count(current_coin + 1, value);

  return count(current_coin, value - coins[current_coin])
      + count(current_coin + 1, value);
}
