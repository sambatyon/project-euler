#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

int divisors(const int &n);

int main(int argc, char **argv) {
  std::vector<int> divs;
  divs.push_back(0);
  for (int i = 1; i < 10000; ++i)
    divs.push_back(divisors(i));
  int res = 0;
  for (int i = 1; i < 10000; ++i)
    if (divs[i] < divs.size() - 1 && i == divs[divs[i]] && i != divs[i])
      res += i;
  std::cout << res << '\n';
  return 0;
}

int divisors(const int &n) {
  const double root = std::sqrt(n);
  const int nroot = static_cast<int>(std::floor(root));
  int res = 0;
  for (int i = 1; i <= nroot; ++i)
    if (n % i == 0)
      res += i + n / i;
  if (nroot * nroot == n)
    res -= nroot;
  return res - n;
}
