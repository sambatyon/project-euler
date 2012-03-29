/*
 * One can save some headaches by using sed + sort:
 * sed s/,/\n/g | sed s/\"// | sort
 * then just feed a program the sorted array
 */
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <set>

std::uint32_t get_worth(const std::string &name);

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "You should pass the file name in the paramters\n";
    return 1;
  }

  std::set<std::string> names;
  std::ifstream file(argv[1]);
  std::string current_name;
  do {
    char c;
    file.read(&c, 1);
    if (c == '"')
      continue;
    if (c == ',') {
      names.insert(current_name);
      current_name = "";
      continue;
    }
    current_name += c;
  } while (!file.eof());
  // add the last one not yet there
  names.insert(current_name);

  unsigned count = 0;
  std::uint64_t addition = 0;
  for (auto s = names.begin(); s != names.end(); ++s) {
    addition += (++count) * get_worth(*s);
  }
  std::cout << addition << '\n';

  return 0;
}

std::uint32_t get_worth(const std::string &name) {
  std::uint32_t worth = 0;
  for (char c : name) {
    worth += c - 'A' + 1;
  }
  return worth;
}
