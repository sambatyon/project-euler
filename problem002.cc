#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  unsigned acc = 0;
  unsigned prev = 1, cur = 2;
  while (cur < 4000000) {
    if (cur % 2 == 0)
      acc += cur;
    unsigned tmp = cur;
    cur += prev;
    prev = tmp;
  }
  std::cout << acc << '\n';
  return 0;
}
