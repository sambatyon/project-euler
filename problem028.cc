#include <iostream>

int main(int argc, char **argv) {
  unsigned last = 1;
  unsigned sum = last;
  unsigned sep = 1;
  while (sep < 1001) {
    for (int i = 0; i < 4; ++i) {
      last += sep + 1;
      sum += last;
    }
    sep += 2;
  }

  std::cout << sum << '\n';
  return 0;
}
