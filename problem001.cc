#include <iostream>

int main() {
  unsigned acc = 0;
  for (unsigned i = 0; i < 1000; ++i)
    if (i % 3 == 0 || i % 5 == 0)
      acc += i;
  std::cout << acc << '\n';
  return 0;
}
