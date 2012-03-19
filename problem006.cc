#include <iostream>

int main(int argc, char **argv) {
  unsigned sum = 0;
  unsigned sqsum = 0;
  for (unsigned i = 1; i <= 100; ++i) {
    sum += i;
    sqsum += i * i;
  }
  std::cout << (sum * sum) - sqsum << '\n';
  return 0;
}
