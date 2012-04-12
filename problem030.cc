#include <iostream>
#include <sstream>
#include <string>
#include <vector>

unsigned compute_5th_power_digits(const unsigned &number);

int main(int argc, char **argv) {
  unsigned lookup[10] = {0};
  lookup[0] = 1;
  for (unsigned i = 1u; i < 10u; ++i)
    lookup[i] = i * i * i * i * i;
  // find the maximum posible number, i.e. using 999… the
  // sum of its powers should have more digits. Given thanks
  // to the way the functions grow
  std::string orig = "9";
  std::string spower;
  unsigned power = 0;
  do {
    orig += "9";
    std::stringstream ssin;
    power = 0;
    for (char c : orig)
      power += lookup[c - '0'];
    ssin << power;
    spower = ssin.str();
  } while (spower.size() >= orig.size());
  unsigned res = 0;
  for (unsigned i = 10u; i < power; i++) {
    unsigned candidate = compute_5th_power_digits(i);
    if (candidate == i)
       res += i;
  }
  std::cout << res << '\n';
  return 0;
}

inline
std::vector<unsigned> create_lookup() {
  std::vector<unsigned> lookup;
  lookup.push_back(0u);
  for (unsigned i = 1u; i < 10u; ++i)
    lookup.push_back(i * i * i * i * i);
  return lookup;
}

unsigned compute_5th_power_digits(const unsigned &number) {
  static std::vector<unsigned> lookup = create_lookup();
  std::stringstream ssin;
  ssin << number;
  std::string snumber = ssin.str();
  unsigned power = 0;
  for (char c : snumber)
    power += lookup[c - '0'];
  return power;
}
