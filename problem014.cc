#include <iostream>
#include <utility>
#include <cstdint>
#include <map>

unsigned find_lenght(const unsigned &x, std::map<unsigned, unsigned> *lookup);

int main(int argc, char **argv) {
  std::map<unsigned, unsigned> lookup;
  lookup.insert(std::make_pair(0U, 0U));
  lookup.insert(std::make_pair(1U, 1U));

  unsigned max = 0;
  unsigned max_index = 0;
  for (unsigned i = 2; i < 1000000; ++i) {
    unsigned length = find_lenght(i, &lookup);
    if (length > max) {
      max = length;
      max_index = i;
    }
  }
  std::cout << max_index << '\n';
  return 0;
}

unsigned find_lenght(const unsigned &x, std::map<unsigned, unsigned> *lookup) {
  if (lookup->find(x) != lookup->end())
    return (*lookup)[x];
  unsigned length;
  if (x % 2 == 0)
    length = find_lenght(x / 2, lookup);
  else
    length = find_lenght(3 * x + 1, lookup);
  lookup->insert(std::make_pair(x, ++length));
  return length;
}
