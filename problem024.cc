#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>

unsigned fact(unsigned n);
std::vector<int> n_th_perm(std::vector<int> elems, const int &nth);

int main(int argc, char **argv) {
  std::vector<int> elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  elements = n_th_perm(elements, 1000000);
  for (int i : elements)
    std::cout << i;
  std::cout << '\n';

  return 0;
}

unsigned fact(unsigned n) {
  unsigned res = 1;
  while (n > 1)
    res *= n--;
  return res;
}

std::vector<int> n_th_perm(std::vector<int> elems, const int &nth) {
  if (elems.size() == 1 && nth != 1) {
    std::cerr << "Invalid value, size == 1 but expected at least " << nth
              << '\n';
    std::exit(1);
  }
  if (elems.size() == 1)
    return elems;
  int perm_rest = fact(elems.size() - 1);
  int interval = 0;
  int elem = 0;
  while (interval < nth) {
    interval += perm_rest;
    ++elem;
  }
  --elem;
  interval -= perm_rest;
  if (elem >= elems.size()) {
    std::cerr << "Invalid permutation number requested\n";
    std::exit(1);
  }
  std::vector<int> perm;
  perm.push_back(elems[elem]);
  elems.erase(elems.begin() + elem);
  std::vector<int> rest = n_th_perm(elems, nth - interval);
  perm.insert(perm.end(), rest.begin(), rest.end());
  return perm;
}
